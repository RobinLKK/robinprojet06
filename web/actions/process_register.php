<!-- web/actions/process_register.php -->
<?php
require_once __DIR__ . '/../includes/db.php';

// Vérification des données du formulaire
if (isset($_POST['email']) && isset($_POST['username']) && isset($_POST['password']) && isset($_POST['confirm_password'])) {
    $email = $_POST['email'];
    $username = $_POST['username'];
    $password = $_POST['password'];
    $confirm_password = $_POST['confirm_password'];
    
    // Vérification des mots de passe
    if ($password !== $confirm_password) {
        header('Location: ../pages/register.php?error=Les mots de passe ne correspondent pas');
        exit();
    }

    // Vérification si l'email existe déjà
    $stmt = $pdo->prepare("SELECT * FROM utilisateurs WHERE email = :email");
    $stmt->execute(['email' => $email]);
    if ($stmt->rowCount() > 0) {
        header('Location: ../pages/register.php?error=Email déjà utilisé');
        exit();
    }

    // Vérification si le nom d'utilisateur existe déjà
    $stmt = $pdo->prepare("SELECT * FROM utilisateurs WHERE username = :username");
    $stmt->execute(['username' => $username]);
    if ($stmt->rowCount() > 0) {
        header('Location: ../pages/register.php?error=Nom d\'utilisateur déjà pris');
        exit();
    }

    // Création de l'utilisateur
    $hashed_password = password_hash($password, PASSWORD_DEFAULT);
    $stmt = $pdo->prepare("INSERT INTO utilisateurs (email, username, password) VALUES (:email, :username, :password)");
    $stmt->execute([
        'email' => $email,
        'username' => $username,
        'password' => $hashed_password
    ]);
    
    // Redirection vers la page de connexion
    header('Location: ../pages/login.php?success=Compte créé avec succès. Vous pouvez maintenant vous connecter.');
    exit();
} else {
    header('Location: ../pages/register.php?error=Veuillez remplir tous les champs');
    exit();
}
?>
<!-- web/actions/process_register.php -->