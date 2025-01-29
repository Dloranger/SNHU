package com.gamingroom;

import java.util.Iterator;

/**
 * Application start-up program
 * 
 * @author D.Loranger based on provided template
 */
public class ProgramDriver {

	private static void printTree() {
		GameService service = GameService.getInstance(); // retrieve/create instance
		// games Iterator creation
		Iterator<Game> gamesIterator = GameService.games.iterator();


		// Iterating over the games list
		while(gamesIterator.hasNext()) {
			String printMsg = "";
			Game gameInstance = gamesIterator.next();
			printMsg = "["+gameInstance.toString() + "]";	

			// create a teams iterator
			Iterator<Team> teamsIterator = gameInstance.teams.iterator();
			// Iterating over the Team list
			while(teamsIterator.hasNext()) {
				Team teamInstance = teamsIterator.next();
				printMsg = printMsg + " [" + teamInstance.toString() + "]";	
				
				// create a players iterator
				Iterator<Player> playersIterator = teamInstance.players.iterator();

				// Iterating over the players list
				while(playersIterator.hasNext()) {
					Player playerInstance = playersIterator.next();
					printMsg = printMsg + " [" + playerInstance.toString() + "]";	

				}
			}
			System.out.println(printMsg);
		}

	}

	/**
	 * The one-and-only main() method
	 * 
	 * @param args command line arguments
	 */
	public static void main(String[] args) {

		//D. Loranger - updated from null to retrieve the instance or create if new
		//GameService service = null); // replace null with ???
		GameService service = GameService.getInstance(); // retrieve/create instance
		System.out.println("\nserviceID: " + service);	

		System.out.println("\n\nAbout to test initializing game data...");

		System.out.println("\n*****************************************************");
		System.out.println("*                                                   *");
		System.out.println("*     ADDING NEW GAMES TO THE SERVICE INSTANCE      *");
		System.out.println("*                                                   *");
		System.out.println("*****************************************************");	

		Game game1 = service.addGame("Game 1");
		Game game2 = service.addGame("Game 2");
		printTree();

		System.out.println("\n*****************************************************");
		System.out.println("*                                                   *");
		System.out.println("*          TESTING DUPLICATE GAME NAMES             *");
		System.out.println("*                                                   *");
		System.out.println("*         ERRORS EXPECTED ON ALL CASES              *");
		System.out.println("*                                                   *");
		System.out.println("*****************************************************");

		Game game3 = service.addGame("Game 1");
		Game game4 = service.addGame("Game 2");
		printTree();


		System.out.println("\n*****************************************************");
		System.out.println("*                                                   *");
		System.out.println("*     ADDING NEW TEAMS TO THE GAME OBJECTS          *");
		System.out.println("*                                                   *");
		System.out.println("*****************************************************");	
		Team team1 = game1.addTeam("Team 1");
		Team team2 = game1.addTeam("Team 2");
		Team team3 = game2.addTeam("Team 3");
		Team team4 = game2.addTeam("Team 4");
		printTree();

		System.out.println("\n*****************************************************");
		System.out.println("*                                                   *");
		System.out.println("*          TESTING DUPLICATE TEAM NAMES             *");
		System.out.println("*                                                   *");
		System.out.println("*         ERRORS EXPECTED ON ALL CASES              *");
		System.out.println("*                                                   *");
		System.out.println("*****************************************************");


		Team team5 = game1.addTeam("Team 1");	
		Team team6 = game1.addTeam("Team 2");
		Team team7 = game2.addTeam("Team 3");
		Team team8 = game2.addTeam("Team 4");
		printTree();



		System.out.println("\n*****************************************************");
		System.out.println("*                                                   *");
		System.out.println("*     ADDING NEW PLAYERS TO THE TEAM OBJECTS        *");
		System.out.println("*                                                   *");
		System.out.println("*****************************************************");	
		Player player1 = team1.addPlayer("Player 1");
		Player player2 = team1.addPlayer("Player 2");
		Player player3 = team2.addPlayer("Player 3");
		Player player4 = team2.addPlayer("Player 4");
		Player player5 = team3.addPlayer("Player 5");
		Player player6 = team3.addPlayer("Player 6");
		Player player7 = team4.addPlayer("Player 7");
		Player player8 = team4.addPlayer("Player 8");
		printTree();



		System.out.println("\n*****************************************************");
		System.out.println("*                                                   *");
		System.out.println("*          TESTING DUPLICATE PLAYER NAMES           *");
		System.out.println("*                 ON THE SAME TEAM                  *");
		System.out.println("*                                                   *");
		System.out.println("*         ERRORS EXPECTED ON ALL CASES              *");
		System.out.println("*                                                   *");
		System.out.println("*****************************************************");
		Player player9 = team1.addPlayer("Player 1");
		Player player10 = team1.addPlayer("Player 2");
		Player player11 = team2.addPlayer("Player 3");
		Player player12 = team2.addPlayer("Player 4");
		Player player13 = team3.addPlayer("Player 5");
		Player player14 = team3.addPlayer("Player 6");
		Player player15 = team4.addPlayer("Player 7");
		Player player16 = team4.addPlayer("Player 8");
		printTree();



		System.out.println("\n*****************************************************");
		System.out.println("*                                                   *");
		System.out.println("*          TESTING DUPLICATE PLAYER NAMES           *");
		System.out.println("*                 ON DIFFERENT TEAMS                *");
		System.out.println("*                                                   *");
		System.out.println("*          ERRORS EXPECTED ON ALL CASES             *");
		System.out.println("*                                                   *");
		System.out.println("*****************************************************");
		Player player17 = team1.addPlayer("Player 3");
		Player player18 = team1.addPlayer("Player 4");
		Player player19 = team2.addPlayer("Player 5");
		Player player20 = team2.addPlayer("Player 6");
		Player player21 = team3.addPlayer("Player 7");
		Player player22 = team3.addPlayer("Player 8");
		Player player23 = team4.addPlayer("Player 1");
		Player player24 = team4.addPlayer("Player 1");
		printTree();

		// use another class to prove there is only one instance
		SingletonTester tester = new SingletonTester();
		tester.testSingleton();
	}
}
