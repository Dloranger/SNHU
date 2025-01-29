package com.gamingroom;

import java.util.Iterator;
import java.util.ArrayList;
import java.util.List;
/**
 * A simple class to hold information about a team
 * <p>
 * Notice the overloaded constructor that requires
 * an id and name to be passed when creating.
 * Also note that no mutators (setters) defined so
 * these values cannot be changed once a team is
 * created.
 * </p>
 * @author coce@snhu.edu
 *
 */
public class Team extends Entity{
	// now part of Entity class
	//long id;
	//String name;
	
	// keep a list of players on the team
	protected List<Player> players = new ArrayList<Player>();
	protected static List<Player> allPlayers = new ArrayList<Player>();
	
	/*
	 * Constructor with an identifier and name
	 */
	public Team(long t_id, String t_name) {
		this.id = t_id;
		this.name = t_name;
	}
	
	/* 
	 * Team is presumed created, now we need to add a player to the Team
	 */
	public Player addPlayer (String t_name) {
		Player newPlayer = null;
		
		// Iterator creation, use the master list of players to ensure no duplication
		Iterator<Player> playerIterator = allPlayers.iterator();

		// Iterating over the list
		while(playerIterator.hasNext()) {
			Player playerInstanceId = playerIterator.next();
			if(playerInstanceId.getName() == t_name) {				
				// player already exists
				System.out.println("ERROR - Player name \"" + t_name + "\" already in use");
				//return playerInstanceId;
				return newPlayer;  // Player already exists
			}
		}
		
		// no match was found for the requested player, create new player
		
		GameService serverInstance = GameService.getInstance();
		newPlayer = new Player (serverInstance.getNextPlayerId(), t_name); 
		
		//add the new player to the list of players
		players.add(newPlayer);
		allPlayers.add(newPlayer);
		return newPlayer;
	}

	/**
	 * @return the id
	 
	public long getId() {
		return id;
	}
	*/

	/**
	 * @return the name
	 
	public String getName() {
		return name;
	}
	 */
	@Override
	public String toString() {
		return "Team [id=" + id + ", name=" + name + "]";
	}
}
