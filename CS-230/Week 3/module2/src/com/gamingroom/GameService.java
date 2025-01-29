package com.gamingroom;
import java.util.Iterator;
import java.util.ArrayList;
import java.util.List;

/**
 * A singleton service for the game engine
 * 
 * @author coce@snhu.edu
 * 
 * Modified to Singleton model D. Loranger 2025-01
 */


public class GameService {

	/**
	 * A list of the active games
	 */
	protected static List<Game> games = new ArrayList<Game>();

	/*
	 * Holds the next game identifier
	 */
	private static long nextGameId = 1;

	 
	/*
	 * Holds the next Team identifier
	 */
	private static long nextTeamId = 1;
	
	
	/*
	 * Holds the next player identifier
	 */
	private static long nextPlayerId = 1;
	
    
	//D. Loranger - new instance variable, which is null by default.
	private static GameService service = null;
	
	//D. Loranger - make constructor private to prevent creating instances
	// outside of this class.  
	//
	// design is modified to represent a 'SINGLETON' structure so only 1
	// instance can exist.
	
	

	protected long getPlayerId() {
		// search for existing player
		
		// return the current value of nextGameID, but also increment for the next time
		return nextPlayerId++;
	}
	
	private void GameService() {
	}
	
	//D. Loranger - public constructor method, creates new instanceId if null
	// otherwise returns the existing instance if already assigned.
	public static GameService getInstance() {
		if (service == null) {
			service = new GameService();
		}
		return service;
	}
	
				
	/**
	 * Construct a new game instance
	 * 
	 * @param name the unique name of the game
	 * @return the game instance (new or existing)
	 */
	public Game addGame(String t_name) {
		

		// a local game instance
		Game game = null;

		// Use iterator to look for existing game with same name
		// if found, simply return the existing instance

		/* 
		 * D. Loranger  completed missing code from straw-man
		 * getGame function will automatically search all instances, no
		 * need to iterate over the list here.
		 * 
		 * intentionally chosen to keep 'name' case sensitive
		 */	
		
		// Iterator creation
		Iterator<Game> gamesIterator = games.iterator();
		
		// Iterating over the list
		while(gamesIterator.hasNext()) {
			Game gameInstanceId = gamesIterator.next();
			if(gameInstanceId.getName() == t_name) {
				//return gameInstanceId;
				
				System.out.println("ERROR - Game name \"" + t_name + "\"  already in use");
				return game;
			}
		}
		// if not found, make a new game instance and add to list of games
		if (game == null) {
			game = new Game(nextGameId++, t_name);
			games.add(game);
		}

		// return the new/existing game instance to the caller
		return game;
	}

	/*
	 * Returns the game instance at the specified index.
	 * <p>
	 * Scope is package/local for testing purposes.
	 * </p>
	 * @param index index position in the list to return
	 * @return requested game instance
	 */
	Game getGame(int index) {
		return games.get(index);
	}
	
	/**
	 * Returns the game instance with the specified id.
	 * 
	 * @param id unique identifier of game to search for
	 * @return requested game instance
	 */
	public Game getGame(long id) {

		// a local game instance
		Game game = null;
		
		// Use iterator to look for existing game with same id
		// if found, simply assign that instance to the local variable
		
		/* D. Loranger - using a temporary variable thisGame as iterator, 
		 * check entire list of games.  If found, return game, otherwise
		 * null will be returned.
		 */
		// Iterator creation
		Iterator<Game> gamesIterator = games.iterator();

		// Iterating over the list
		while(gamesIterator.hasNext()) {
			Game gameInstanceId = gamesIterator.next();
			if(gameInstanceId.getId() == id) {
				return gameInstanceId;
			}
		}
		return game;
	}

	/**
	 * Returns the game instance with the specified name.
	 * 
	 * @param name unique name of game to search for
	 * @return requested game instance
	 */
	public Game getGame(String name) {

		// a local game instance
		Game game = null;

		// Use iterator to look for existing game with same name
		// if found, simply assign that instance to the local variable
		
		// Iterator creation
		Iterator<Game> gamesIterator = games.iterator();

		// Iterating over the list
		while(gamesIterator.hasNext()) {
			Game gameInstanceId = gamesIterator.next();
			if(gameInstanceId.getName() == name) {
				return gameInstanceId;
			}
		}
		return game;

	}

	/**
	 * Returns the number of games currently active
	 * 
	 * @return the number of games currently active
	 */
	public int getGameCount() {
		return games.size();
	}

	/*
	 * Returns the next player ID
	 */
	protected long getNextPlayerId() {
		
		// return the current value of nextPlayerID, but also increment for the next time
		return nextPlayerId++;
	}

	/*
	 * Returns the next Team ID
	 */
	protected long getNextTeamId() {
		
		// return the current value of nextTeamID, but also increment for the next time
		return nextTeamId++;
	}
}
