<?php
session_start();
if (isset($_SESSION['user_id'])) {
    echo "Utilisateur connecté avec l'ID : " . $_SESSION['user_id'];
} else {
    echo "Aucun utilisateur connecté.";
}
?>
