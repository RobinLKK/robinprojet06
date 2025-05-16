<!-- web/pages/leaderboard.php -->
<?php
session_start();
require_once __DIR__ . '/../includes/db.php';

// Vérification de connexion
if (!isset($_SESSION['user_id'])) {
    header('Location: login.php');
    exit();
}

// Récupération des scores
$stmt = $pdo->prepare("SELECT username, score FROM scores JOIN utilisateurs ON scores.user_id = utilisateurs.id ORDER BY score DESC LIMIT 10");
$stmt->execute();
$scores = $stmt->fetchAll(PDO::FETCH_ASSOC);
?>

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Leaderboard - The Big Bang ISEN</title>
    <link rel="stylesheet" href="../css/leaderboard.css">
</head>
<body>
    <header>
        <h1>Leaderboard</h1>
        <nav>
            <ul>
                <li><a href="index.php">Accueil</a></li>
                <li><a href="leaderboard.php">Leaderboard</a></li>
                <li><a href="../actions/process_logout.php">Se déconnecter</a></li>
            </ul>
        </nav>
    </header>
    
    <main>
        <h2>Top 10 des joueurs</h2>
        <table>
            <thead>
                <tr>
                    <th>Rang</th>
                    <th>Nom d'utilisateur</th>
                    <th>Score</th>
                </tr>
            </thead>
            <tbody>
                <?php
                $rank = 1;
                foreach ($scores as $score) {
                    echo "<tr>";
                    echo "<td>" . $rank . "</td>";
                    echo "<td>" . htmlspecialchars($score['username']) . "</td>";
                    echo "<td>" . $score['score'] . "</td>";
                    echo "</tr>";
                    $rank++;
                }
                ?>
            </tbody>
        </table>
    </main>
    
    <footer>
        <p>&copy; 2025 The Big Bang ISEN. All rights reserved.</p>
    </footer>
</body>
</html>
