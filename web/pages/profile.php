<?php
session_start();
require '../includes/db.php';
require '../includes/functions.php';

if (!isLoggedIn()) {
    header("Location: login.php");
    exit();
}

$user_id = $_SESSION['user_id'];
$user = getUserProfile($pdo, $user_id);
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Profil de <?php echo htmlspecialchars($user['username']); ?></title>
    <link rel="stylesheet" href="../css/profile.css">
    <link href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.0/css/all.min.css" rel="stylesheet">
</head>
<body>
    <div class="profile-container">
        <!-- Bouton retour (flèche) -->
        <a href="index.php" class="back-arrow">
            <i class="fas fa-arrow-left"></i>
        </a>

        <img src="../<?php echo htmlspecialchars($user['avatar']); ?>" alt="Avatar de <?php echo htmlspecialchars($user['username']); ?>" class="profile-avatar">
        <h2><?php echo htmlspecialchars($user['username']); ?></h2>
        <p>Email : <?php echo htmlspecialchars($user['email']); ?></p>
        <p>Bio : <?php echo htmlspecialchars($user['bio']); ?></p>
        <p>Meilleur score : <?php echo htmlspecialchars($user['best_score']); ?></p>
        <p>Total de parties jouées : <?php echo htmlspecialchars($user['total_games']); ?></p>
        <p>Temps total joué : <?php echo htmlspecialchars($user['total_time_played']); ?> secondes</p>

        <!-- Boutons -->
        <a href="edit_profile.php" class="primary-btn">Modifier le profil</a>
        <a href="login.php" class="secondary-btn">Déconnexion</a>
    </div>
</body>
</html>


