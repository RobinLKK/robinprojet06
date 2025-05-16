<!-- web/pages/index.php -->
<?php
session_start();
require_once __DIR__ . '/../includes/db.php';
require_once __DIR__ . '/../includes/functions.php';

if (!isset($_SESSION['user_id'])) {
    header('Location: login.php');
    exit();
}
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>The Big Bang ISEN</title>
    <link rel="stylesheet" href="../css/main.css">
    <script src="../js/main.js" defer></script>
</head>
<body>
    <header>
        <h1>Bienvenue sur The Big Bang ISEN</h1>
        <nav>
            <ul>
                <li><a href="index.php">Accueil</a></li>
                <li><a href="leaderboard.php">Classement</a></li>
                <li><a href="profile.php">Profil</a></li>
                <li><a href="../actions/process_logout.php">Se déconnecter</a></li>
            </ul>
        </nav>
    </header>
    
    <main>
        <h2>Coucou, <?php echo htmlspecialchars($_SESSION['username']); ?> !</h2>
        <p>Bienvenue sur The Big Bang ISEN project.</p>

    <!-- Bouton Jouer -->
        <div class="play-button-container">
            <a href="game.php" class="play-button">Jouer</a>
        </div>

    </main>
    
    <footer>
        <p>&copy; 2025 The Big Bang ISEN. All rights reserved.</p>
    </footer>
</body>
</html>
