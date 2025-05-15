<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Welcome</title>
</head>
<body>
    <form method="post">
        <button type="submit" name="action" value="weather">WEATHER</button>
    </form>
    <?php
    if (isset($_POST['action'])) {
        $action = $_POST['action'];
        if ($action == 'weather') {
            $output = shell_exec('python3 ./script/weather.py');
            echo "<pre>$output</pre>";
        }
    }
    ?>
</body>
</html>