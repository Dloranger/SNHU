/*
* Daniel Loranger
*  CS-320
* 
* Requirements provided:
* The contact service shall be able to add contacts with a unique ID.
* The contact service shall be able to delete contacts per contact ID.
* The contact service shall be able to update contact fields per contact ID. 
* The following fields are updatable:
*** firstName
*** lastName
*** Number
*** Address
*/

package Contact;


public class Contact {
	//behavioral constants
	public static final boolean uniqueIDupdatable = false;  //disallowed by requirements
	private int idLengthMax = 10;
	private int firstNameLengthMax = 10;
	private int lastNameLengthMax = 10;
	private int phoneLength = 10;
	private int addressLengthMax = 30;
    
	// contact details
	private String uniqueID;
	private String firstName;
	private String lastName;
	private String phoneNumber;
	private String address;
	
	/******************** private functions  ******************/
	private boolean uniqueIDValid (String ID)
		{
		/*
		 * The contact object shall have a required unique contact ID string 
		 * that cannot be longer than 10 characters. 
		 * The contact ID shall not be null and shall not be updatable.
		 */
		    if (ID == null || ID.length() > idLengthMax) {
		        return false;
		    }
		    return true;
		}
	private boolean firstNameValid (String name)
	{
		/*
		 * The contact object shall have a required firstName String 
		 * that cannot be longer than 10 characters. 
		 * The firstName field shall not be null.
		 */
		if ((name != null) && (!name.isEmpty()) && (name.length() <= firstNameLengthMax)) 
		{
			return true;
		}
		else {
			return false;
		}
	}
	private boolean lastNameValid (String name)
	{
		/*
		 * The contact object shall have a required lastName String 
		 * that cannot be longer than 10 characters. 
		 * The lastName field shall not be null.
		 */
		if ((name != null) && (!name.isEmpty()) && (name.length() <= lastNameLengthMax)) 
		{
			return true;
		}
		else {
			return false;
		}
	}
	private boolean phoneValid (String phone)
	{
		/*
		 *The contact object shall have a required phone String field 
		 *that must be exactly 10 digits. 
		 *The phone field shall not be null. 
		 */
		if ((phone != null) && (phone.length() == phoneLength) && (phone.matches("[0-9]+")))  
		{
			return true;
		}
		else {
			return false;
		}
	}
	private boolean addressValid (String address)
	{
		if ((address != null) && (!address.isEmpty() ) && (address.length() <= addressLengthMax)) 
		{
			return true;
		}
		else {
			return false;
		}
	}
	
	/******************** public functions  *******************/
	//constructor
	public Contact(
		String constructorUniqueID,
		String constructorFirstName,
		String constructorLastName,
		String constructorPhoneNumber,
		String constructorAddress)
		{
		//check inputs are valid
		if (!uniqueIDValid(constructorUniqueID)) {
			throw new IllegalArgumentException ("Invalid ID");
		}
		if (!firstNameValid(constructorFirstName)) {
			throw new IllegalArgumentException ("Invalid first name");
		}
		if (!lastNameValid(constructorLastName)) {
			throw new IllegalArgumentException ("Invalid last name");
		}
		if (!phoneValid(constructorPhoneNumber)) {
			throw new IllegalArgumentException ("Invalid phone number");
		}
		if (!addressValid(constructorAddress)) {
			throw new IllegalArgumentException ("Invalid address");
		}
		// we made it this far, must be okay to proceed
		this.uniqueID = constructorUniqueID.toUpperCase();
		this.firstName = constructorFirstName;
		this.lastName = constructorLastName;
		this.phoneNumber = constructorPhoneNumber;
		this.address = constructorAddress;
	    
	}// constructor
	
	//Getters
	public String getUniqueID ()
	{
		return this.uniqueID;
	} //getUniqueID
	public String getFirstName ()
	{
		return this.firstName;
	} //getFirstName
	public String getLastName ()
	{
		return this.lastName;
	} //getlastName
	public String getPhoneNumber ()
	{
		return this.phoneNumber;
	} //getPhoneNumber
	public String getAddress ()
	{
		return this.address;
	} //getAddress	

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
	 *  update contact first name 
	 *  
	 *  @param name String
	 *  @return boolean true = success
	 *  
	 */
	public boolean setFirstName(String name) {
		if (firstNameValid(name)) 
		{
		this.firstName = name;
		return true;
		}
		else {
			return false;
		}
	}//setFirstName

	/*
	 *  update contact last name 
	 *  
	 *  @param name String
	 *  @return boolean true = success
	 *  
	 */
	public boolean setLastName(String name) {
		if (lastNameValid(name)) 
		{
		this.lastName = name;
		return true;
		}
		else {
			return false;
		}
	}//setLastName

	/*
	 *  update contact phone number 
	 *  
	 *  @param phone String
	 *  @return boolean true = success
	 *  
	 */
	public boolean setPhoneNumber(String phone) {
		if (phoneValid(phone)) 
		{
		this.phoneNumber = phone;
		return true;
		}
		else {
			return false;
		}
	}//setPhoneNumber

	/*
	 *  update contact address 
	 *  
	 *  @param address String
	 *  @return boolean true = success
	 *  
	 */
	public boolean setAddress(String address) {
		if (addressValid(address)) 
		{
		this.address = address;
		return true;
		}
		else {
			return false;
		}
	}//setAddress

} // class Contact