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

import java.util.List;
import java.util.ArrayList;

public class ContactService {

	// In-memory list to hold Contact objects
	private static List<Contact> contactList = new ArrayList<Contact>();

	// Counter for generating next unique ID
	private static long counter = 0L; 

	/******************** private functions  ******************/
	
	
	// Check if an ID already exists in the contact list
	private static boolean idExists(String id) {
		for (Contact c : contactList) {
			if (c.getUniqueID().toUpperCase().equals(id.toUpperCase())) {
				return true;
			}
		}
		return false;
	}

	/******************** public functions  *******************/
	/*
	 * unit test system helper function to reset the contacts list
	 *  
	 */
	public static void clearAllContacts() {
	    contactList.clear();
	    counter = 0L; // optional, but nice for repeatable tests
	}
	
	
	/*
	 * Generates the next available sequential alphanumeric ID (base-36, max 10 chars).
	 * The method increments the internal counter until a unique (unused) ID is found.
	 * It does NOT scan for the maximum ID or reset the counter.
	 *
	 * @return A unique ID string.
	 * 
	 * AI generated function
	 */
	public static String getNextUniqueID() {
		while (true) {
			counter++; // move to the next numeric value
			// Convert counter to base-36 (0-9, A-Z)
			String id = Long.toString(counter, 36).toUpperCase();

			// Truncate if longer than 10 characters
			if (id.length() > 10) {
				id = id.substring(id.length() - 10).toUpperCase();
			}
			// Skip IDs that already exist
			if (!idExists(id.toUpperCase())) {
				return id;    // Found a free one ? return it
			}
			// loop and try the next counter value
		}
	}
	
	
	/*
	 *  add contact with field data supplied
	 *  contact ID is automatically generated based on next available
	 *  alphanumeric character
	 *  
	 *  There is a risk of running out of IDs that is not handled ,but
	 *  10^26 is a lot of entries to run out with 
	 *  
	 *  @param Contact
	 *  @return UniqueID
	 *  
	 */  
	public String createContact(String firstName, String lastName, String phone, String address) {
	    
		String id = getNextUniqueID().toUpperCase();
	    
		Contact contact = new Contact(id.toUpperCase(), firstName, lastName, phone, address);
	    
		addContact(contact);
	    
	    return contact.getUniqueID().toUpperCase();
	}

	/*
	 *  add contact per contact ID String
	 *  
	 *  @param Contact
	 *  @return boolean true = success
	 */
	public boolean addContact(Contact contact) {
		// Check if ID already exists
		for (Contact c : contactList) {
			if (c.getUniqueID().toUpperCase().equals(contact.getUniqueID().toUpperCase())) {
				return false;   // duplicate ID, do not add
			}
		}

		contactList.add(contact);

		return true;
	}


	/*
	 *  Delete a contact per contact ID String
	 *  
	 *  @param ContactID String
	 *  @return boolean true = success
	 *  
	 */
	public boolean deleteContact(String contactID) {
		//increment thru existing contact looking for a match
		for (int i = 0; i < contactList.size(); i++) {
			Contact c = contactList.get(i);
			if (c.getUniqueID().toUpperCase().equals(contactID.toUpperCase())) {
				contactList.remove(i);
				return true;  // contact removed
			}
		}

		// contact not found
		return false;
	}


	/*
	 *  update contact per contact ID String
	 *  
	 *  @param ContactID String
	 *  @param firstName String
	 *  @return boolean true = success
	 *  
	 */
	public boolean updateContactFirstName(String contactID, String firstName) {
		for (Contact c : contactList) {
			if (c.getUniqueID().toUpperCase().equals(contactID.toUpperCase())) {
				// rely on Contact's validation
				return c.setFirstName(firstName);
			}
		}

		// contact not found
		return false;
	}

	/*
	 *  update contact per contact ID String
	 *  
	 *  @param ContactID String
	 *  @param lastName String
	 *  @return boolean true = success
	 *  
	 */
	public boolean updateContactLastName(String contactID, String lastName) {
		for (Contact c : contactList) {
			if (c.getUniqueID().toUpperCase().equals(contactID.toUpperCase())) {
				return c.setLastName(lastName);
			}
		}

		return false;
	}


	/*
	 *  update contact per contact ID String
	 *  
	 *  @param ContactID String
	 *  @param PhoneNumber String
	 *  @return boolean true = success
	 *  
	 */
	public boolean updateContactPhone(String contactID, String phoneNumber) {

		for (Contact c : contactList) {
			if (c.getUniqueID().toUpperCase().equals(contactID.toUpperCase())) {
				return c.setPhoneNumber(phoneNumber);
			}
		}
		return false;
	}


	/*
	 *  update contact per contact ID String
	 *  
	 *  @param ContactID String
	 *  @param address String
	 *  @return boolean true = success
	 *  
	 */
	public boolean updateContactAddress(String contactID, String address) {

		for (Contact c : contactList) {
			if (c.getUniqueID().toUpperCase().equals(contactID.toUpperCase())) {
				return c.setAddress(address);
			}
		}

		return false;
	}

} // class ContactService

