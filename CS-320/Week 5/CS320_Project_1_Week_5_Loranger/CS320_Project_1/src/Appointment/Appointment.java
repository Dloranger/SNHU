/*
 * Daniel Loranger
 *  CS-320
 */

package Appointment;

import java.util.Date;

public class Appointment {
	//behavioral constants
	public static final boolean uniqueIDupdatable = false;  //disallowed by requirements
	private int idLengthMax = 10;
	private int descriptionLengthMax = 50;

	// contact details
	private String uniqueID;
	private Date date;
	private String description;

	/******************** private functions  ******************/
	/*
	 *  Helper  - checks if unique ID is valid or not 
	 *  
	 *  @return bool - true = valid
	 */
	private boolean uniqueIDValid (String ID)
	{
		/*
		 * The object shall have a required unique ID string 
		 * that cannot be longer than 10 characters. 
		 * The object ID shall not be null and shall not be updatable.
		 */
		if (ID == null || ID.length() > idLengthMax) {
			return false;
		}
		return true;
	}
	/*
	 *  Helper  - checks if description is valid
	 *  
	 *  @return bool - true = valid
	 */
	private boolean descriptionValid (String description)
	{
		/*
		 * The object shall have a required description String 
		 * that cannot be longer than 50 characters. 
		 * The description field shall not be null.
		 */
		if ((description != null) && (!description.isEmpty()) && 
				(description.length() <= descriptionLengthMax)) 
		{
			return true;
		}
		else {
			return false;
		}
	}
	/*
	 *  Helper  - checks if date is valid or not 
	 *  
	 *  @return bool - true = valid
	 */
	private boolean dateValid (Date date)
	{
		/*
		 * Helper function that ensures the date provided
		 * is not null and also not in the past
		 */
		if ((date != null) && (!date.before(new Date()) )) 
		{
			return true;
		}
		else {
			return false;
		}
	}

	/******************** public functions  *******************/
	/*
	 *  Constructor  - Creates a new appointment object 
	 *  
	 *  @param constructorUniqueID - String <= 10 Char (AlphaNum - CAPS)
	 *  @param constructorDate - Date in the future
	 *  @param constructorDescription - String <= 50 chars
	 *  
	 *  @return boolean true = success
	 */
	public Appointment(
			String constructorUniqueID,
			Date   constructorDate,
			String constructorDescription)
	{
		//check inputs are valid
		if (!uniqueIDValid(constructorUniqueID)) {
			throw new IllegalArgumentException ("Invalid ID");
		}
		if (!dateValid(constructorDate)) {
			throw new IllegalArgumentException ("Invalid date");
		}
		if (!descriptionValid(constructorDescription)) {
			throw new IllegalArgumentException ("Invalid description");
		}
		// we made it this far, must be okay to proceed
		this.uniqueID = constructorUniqueID.toUpperCase();
		this.date = constructorDate;
		this.description = constructorDescription;
	}// constructor

	/********************* Getters  *******************/
	/*
	 *  Getter  - Returns the objects unique ID 
	 *  
	 *  @return uniqueID - String <= 10 chars
	 */
	public String getUniqueID ()
	{
		return this.uniqueID;
	} //getUniqueID
	/*
	 *  Getter  - Returns the objects date 
	 *  
	 *  @return date - Date
	 */
	public Date getDate ()
	{
		return this.date;
	} //getDate
	/*
	 *  Getter  - Returns the objects description 
	 *  
	 *  @return description - String <= 50 chars
	 */
	public String getDescription()
	{
		return this.description;
	} //getDescription	

	/********************* Setters  *******************/

	/*
	 *  Setter - update appointment ID 
	 *  
	 *  @param ID - String <=10 chars
	 *  @return boolean true = success
	 *  
	 */
	public boolean setUniqueID(String ID) {
		// only allow if the requirement is changed to allow
		// the field to be updatable
		if (uniqueIDupdatable == true) 
		{
			if (uniqueIDValid(ID)) 
			{
				this.uniqueID = ID.toUpperCase();
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}//setUniqueId

	/*
	 *  setter - update appointment date
	 *  
	 *  @param date Date
	 *  @return boolean true = success
	 *  
	 */
	public boolean setDate(Date date) {
		if (dateValid(date)) 
		{
			this.date = date;
			return true;
		}
		else {
			return false;
		}
	}//setDate

	/*
	 *  setter - update description 
	 *  
	 *  @param description String
	 *  @return boolean true = success
	 *  
	 */
	public boolean setDescription(String description) {
		if (descriptionValid(description)) 
		{
			this.description = description;
			return true;
		}
		else {
			return false;
		}
	}//setDescription

} // class Appointment