<?php
do {
	$user_choice = readline("Choose rock, paper, or scissors: ");
	$user_choice = strtolower($user_choice);

	$choices = array('rock', 'paper', 'scissors');
	while (!in_array($user_choice, $choices)) {
		$user_choice = readline("Choose rock, paper, or scissors: ");
		$user_choice = strtolower($user_choice);
	}
	$play_again = true;
	$computer_choice = $choices[array_rand($choices)];

	if ($user_choice == $computer_choice) {
		echo "It's a tie!\n";
	} elseif (($user_choice == 'rock' && $computer_choice == 'scissors') || 
			  ($user_choice == 'paper' && $computer_choice == 'rock') || 
			  ($user_choice == 'scissors' && $computer_choice == 'paper')) {
		echo "Congratulations! You won! The computer chose $computer_choice.\n";
		$play_again = false;
	} else {
		echo "Sorry, you lost. The computer chose $computer_choice.\n";
		$play_again = false;
	}
} while ($play_again == true);
?>
