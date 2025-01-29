package com.gamingroom;


/*
 * 
 *  A superclass that contains entities from Game, Team and player classes.
 */

public class Entity {
	
	protected long id;
	protected String name;
	
	protected Entity() {
		// nothing done here.
	}
	
	//public constructor
	public Entity(long t_id, String t_name) {
		this.id = t_id;
		this.name = t_name;
	}
	
	/* 
	 * public fetcher that returns entity ID
	 * 
	 * */
	public long getId() {
		return id;
	}
	
	/* 
	 *  public fetcher that returns entity name
	 */
	public String getName() {
		return name;
	}
	
	@Override
	public String toString() {
		return "Game [id=" + id + ", name=" + name + "]";
	}
}
