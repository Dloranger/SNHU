/*
* Daniel Loranger
*  CS-320
*/

package Task;


public class Task {
	//behavioral constants
	public static final boolean uniqueIDupdatable = false;  //disallowed by requirements
	private int idLengthMax = 10;
	private int nameLengthMax = 20;
	private int descriptionLengthMax = 50;
    
	// contact details
	private String uniqueID;
	private String name;
	private String description;
	
	/******************** private functions  ******************/
	private boolean uniqueIDValid (String ID)
		{
		/*
		 * The task object shall have a required unique ID string 
		 * that cannot be longer than 10 characters. 
		 * The ID shall not be null and shall not be updatable.
		 */
		    if (ID == null || ID.length() > idLengthMax) {
		        return false;
		    }
		    return true;
		}
	private boolean nameValid (String name)
	{
		/*
		 * The task object shall have a required name String 
		 * that cannot be longer than 20 characters. 
		 * The name field shall not be null.
		 */
		if ((name != null) && (!name.isEmpty()) && (name.length() <= nameLengthMax)) 
		{
			return true;
		}
		else {
			return false;
		}
	}

	private boolean descriptionValid (String description)
	{
		/*
		 * The task object shall have a required description String 
		 * that cannot be longer than 50 characters. 
		 * The description field shall not be null.
		 */
		if ((description != null) && (!description.isEmpty() ) && (description.length() <= descriptionLengthMax)) 
		{
			return true;
		}
		else {
			return false;
		}
	}
	
	/******************** public functions  *******************/
	//constructor
	public Task(
		String constructorUniqueID,
		String constructorName,
		String constructorDescription)
		{
		//check inputs are valid
		if (!uniqueIDValid(constructorUniqueID)) {
			throw new IllegalArgumentException ("Invalid ID");
		}
		if (!nameValid(constructorName)) {
			throw new IllegalArgumentException ("Invalid name");
		}
		if (!descriptionValid(constructorDescription)) {
			throw new IllegalArgumentException ("Invalid description");
		}
		// we made it this far, must be okay to proceed
		this.uniqueID = constructorUniqueID.toUpperCase();
		this.name = constructorName;
		this.description = constructorDescription;
	    
	}// constructor
	
	//Getters
	public String getUniqueID ()
	{
		return this.uniqueID;
	} //getUniqueID
	public String getName ()
	{
		return this.name;
	} //getName

	public String getDescription ()
	{
		return this.description;
	} //getDescription	

	/********************* Setters  *******************/
	
	/*
	 *  update contact ID 
	 *  
	 *  @param ID String
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
	 *  update contact name 
	 *  
	 *  @param name String
	 *  @return boolean true = success
	 *  
	 */
	public boolean setName(String name) {
		if (nameValid(name)) 
		{
		this.name = name;
		return true;
		}
		else {
			return false;
		}
	}//setName


	/*
	 *  update contact description 
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

} // class Task