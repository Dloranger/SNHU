package com.gamingroom;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
/**
 * A simple class to hold information about a game
 * 
 * <p>
 * Notice the overloaded constructor that requires
 * an id and name to be passed when creating.
 * Also note that no mutators (setters) defined so
 * these values cannot be changed once a game is
 * created.
 * </p>
 * 
 * @author coce@snhu.edu
 *
 */
public class Game extends Entity {
	
	/**
	 * A list of the active Teams
	 */
	protected List<Team> teams = new ArrayList<Team>();
	protected static List<Team> allTeams = new ArrayList<Team>();
	
	
	// now part of Entity class
	//long id;  
	//String name;
	
	/**
	 * Hide the default constructor to prevent creating empty instances.
	 */
	private Game() {
	}

	/**
	 * Constructor with an identifier and name
	 */
	public Game(long t_id, String t_name) {
		this();
		this.id = t_id;
		this.name = t_name;
	}
	
	
	/* 
	 * Game is presumed created, now we need to add a team to the game
	 */
	public Team addTeam (String t_name) {
		Team newTeam = null;
		
		// Iterator creation, use the master list of teams to ensure no duplication
		Iterator<Team> teamIterator = allTeams.iterator();

		// Iterating over the list
		while(teamIterator.hasNext()) {
			Team teamInstanceId = teamIterator.next();
			if(teamInstanceId.getName() == t_name) {				
				// team already exists
				//return teamInstanceId;
				System.out.println("ERROR - Team name \"" + t_name + "\" already in use");
				return newTeam;
			}
		}
		
		// no match was found for the requested team, create new team
		
		GameService serverInstance = GameService.getInstance();
		newTeam = new Team (serverInstance.getNextTeamId(), t_name); 
		
		//add the new team to the list of teams
		teams.add(newTeam);
		allTeams.add(newTeam);
		return newTeam;
	}

	/**
	 * @return the id
	 */
	// now part of Entity class
	/*public long getId() {
		return id;
	}
	*/

	/**
	 * @return the name
	 */
	// now part of Entity class
	/*
	public String getName() {
		return name;
	}
*/
	
	@Override
	public String toString() {
		
		return "Game [id=" + id + ", name=" + name + "]";
	}

}
