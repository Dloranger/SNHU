package Test;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;

import Contact.Contact;

class  ContactTest {

	@DisplayName ("Contact_constructor_valid")
	@Test
	void Contact_constructor_valid() { 
		/* 
		 * Implement a constructor 
		 * -unique ID = 10 chars max
		 * -first name = 10 chars max
		 * -last name = 10 chars max
		 * -phone = 10 digits
		 * -address = 30 chars max
		 * */

		String contactID = "9999999999";
		String firstName = "Daniel1234";
		String lastName  = "Loranger12";
		String phoneNumber = "1234567890";
		String address = "123 Main Street 12345678901234";

		Contact Contact = new Contact(contactID,firstName,lastName,phoneNumber,address);

		assertEquals(contactID, Contact.getUniqueID());
		assertEquals(firstName, Contact.getFirstName());
		assertEquals(lastName, Contact.getLastName());
		assertEquals(phoneNumber, Contact.getPhoneNumber());
		assertEquals(address, Contact.getAddress());
	}


	@DisplayName ("Contact_constructorUniqueID_invalid")
	@Test
	void Contact_constructorUniqueID_invalid() { 
		/* 
		 * Implement a constructor 
		 * -unique ID = 10 chars max
		 * -first name = 10 chars max
		 * -last name = 10 chars max
		 * -phone = 10 digits
		 * -address = 30 chars max
		 * */

		String contactID = "99999999990"; // invalid
		String firstName = "Daniel1234";
		String lastName = "Loranger12";
		String phoneNumber = "1234567890";
		String address = "123 Main Street 12345678901234";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact(contactID, firstName, lastName, phoneNumber, address);
		});
	}

	@DisplayName ("Contact_constructorFirstName_invalid")
	@Test
	void Contact_constructorFirstName_invalid() { 
		/* 
		 * Implement a constructor 
		 * -unique ID = 10 chars max
		 * -first name = 10 chars max
		 * -last name = 10 chars max
		 * -phone = 10 digits
		 * -address = 30 chars max
		 * */

		String contactID = "9999999999";
		String firstName = "Daniel12345"; //invalid
		String lastName  = "Loranger12";
		String phoneNumber = "1234567890";
		String address = "123 Main Street 12345678901234";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact(contactID, firstName, lastName, phoneNumber, address);
		});
	}


	@DisplayName ("Contact_constructorLastName_invalid")
	@Test
	void Contact_constructorLastName_invalid() { 
		/* 
		 * Implement a constructor 
		 * -unique ID = 10 chars max
		 * -first name = 10 chars max
		 * -last name = 10 chars max
		 * -phone = 10 digits
		 * -address = 30 chars max
		 * */

		String contactID = "9999999999";
		String firstName = "Daniel1234";
		String lastName  = "Loranger123";//invalid
		String phoneNumber = "1234567890";
		String address = "123 Main Street 12345678901234";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact(contactID, firstName, lastName, phoneNumber, address);
		});
	}

	@DisplayName ("Contact_constructorPhone_invalid")
	@Test
	void Contact_constructorPhone_invalid() { 
		/* 
		 * Implement a constructor 
		 * -unique ID = 10 chars max
		 * -first name = 10 chars max
		 * -last name = 10 chars max
		 * -phone = 10 digits
		 * -address = 30 chars max
		 * */

		String contactID = "9999999999";
		String firstName = "Daniel1234";
		String lastName  = "Loranger12";
		String phoneNumber = "12345678901"; //invalid
		String address = "123 Main Street 12345678901234";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact(contactID, firstName, lastName, phoneNumber, address);
		});
	}

	@DisplayName ("Contact_constructorAddress_invalid")
	@Test
	void Contact_constructorAddress_invalid() { 
		/* 
		 * Implement a constructor 
		 * -unique ID = 10 chars max
		 * -first name = 10 chars max
		 * -last name = 10 chars max
		 * -phone = 10 digits
		 * -address = 30 chars max
		 * */

		String contactID = "9999999999";
		String firstName = "Daniel1234";
		String lastName  = "Loranger12";
		String phoneNumber = "1234567890";
		String address = "123 Main Street 123456789012345"; //invalid

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact(contactID, firstName, lastName, phoneNumber, address);
		});
	}

	@DisplayName ("Contact_updateContactID_invalid")
	@Test
	void Contact_updateContactID_invalid() {

		String contactID = "9999999999";
		String firstName = "Daniel1234";
		String lastName  = "Loranger12";
		String phoneNumber = "1234567890";
		String address = "123 Main Street 12345678901234";

		Contact contact = new Contact(contactID, firstName, lastName, phoneNumber, address);

		// Try updating ID (should fail), be sure to use an otherwise valid value
		boolean result = contact.setUniqueID("0123456789");

		assertFalse(result);                            // update should not be allowed
		assertEquals(contactID, contact.getUniqueID()); // ID should remain unchanged
	}

	@DisplayName("Contact_constructorUniqueID_null_invalid")
	@Test
	void Contact_constructorUniqueID_null_invalid() {
		String contactID = null; // invalid: null
		String firstName = "Daniel1234";
		String lastName  = "Loranger12";
		String phoneNumber = "1234567890";
		String address = "123 Main Street 12345678901234";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact(contactID, firstName, lastName, phoneNumber, address);
		});
	}

	@DisplayName("Contact_constructorFirstName_null_invalid")
	@Test
	void Contact_constructorFirstName_null_invalid() {
		String contactID = "9999999999";
		String firstName = null; // invalid
		String lastName  = "Loranger12";
		String phoneNumber = "1234567890";
		String address = "123 Main Street 12345678901234";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact(contactID, firstName, lastName, phoneNumber, address);
		});
	}

	@DisplayName("Contact_constructorFirstName_empty_invalid")
	@Test
	void Contact_constructorFirstName_empty_invalid() {
		String contactID = "9999999999";
		String firstName = ""; // invalid
		String lastName  = "Loranger12";
		String phoneNumber = "1234567890";
		String address = "123 Main Street 12345678901234";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact(contactID, firstName, lastName, phoneNumber, address);
		});
	}

	@DisplayName("Contact_constructorLastName_null_invalid")
	@Test
	void Contact_constructorLastName_null_invalid() {
		String contactID = "9999999999";
		String firstName = "Daniel1234";
		String lastName  = null; // invalid
		String phoneNumber = "1234567890";
		String address = "123 Main Street 12345678901234";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact(contactID, firstName, lastName, phoneNumber, address);
		});
	}

	@DisplayName("Contact_constructorLastName_empty_invalid")
	@Test
	void Contact_constructorLastName_empty_invalid() {
		String contactID = "9999999999";
		String firstName = "Daniel1234";
		String lastName  = ""; // invalid
		String phoneNumber = "1234567890";
		String address = "123 Main Street 12345678901234";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact(contactID, firstName, lastName, phoneNumber, address);
		});
	}

	@DisplayName("Contact_constructorPhone_null_invalid")
	@Test
	void Contact_constructorPhone_null_invalid() {
		String contactID = "9999999999";
		String firstName = "Daniel1234";
		String lastName  = "Loranger12";
		String phoneNumber = null; // invalid
		String address = "123 Main Street 12345678901234";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact(contactID, firstName, lastName, phoneNumber, address);
		});
	}

	@DisplayName("Contact_constructorPhone_tooShort_invalid")
	@Test
	void Contact_constructorPhone_tooShort_invalid() {
		String contactID = "9999999999";
		String firstName = "Daniel1234";
		String lastName  = "Loranger12";
		String phoneNumber = "123456789"; // 9 digits, invalid
		String address = "123 Main Street 12345678901234";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact(contactID, firstName, lastName, phoneNumber, address);
		});
	}

	@DisplayName("Contact_constructorPhone_nonDigit_invalid")
	@Test
	void Contact_constructorPhone_nonDigit_invalid() {
		String contactID = "9999999999";
		String firstName = "Daniel1234";
		String lastName  = "Loranger12";
		String phoneNumber = "12345abcde"; // invalid chars
		String address = "123 Main Street 12345678901234";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact(contactID, firstName, lastName, phoneNumber, address);
		});
	}

	@DisplayName("Contact_constructorAddress_null_invalid")
	@Test
	void Contact_constructorAddress_null_invalid() {
		String contactID = "9999999999";
		String firstName = "Daniel1234";
		String lastName  = "Loranger12";
		String phoneNumber = "1234567890";
		String address = null; // invalid

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact(contactID, firstName, lastName, phoneNumber, address);
		});
	}

	@DisplayName("Contact_constructorAddress_empty_invalid")
	@Test
	void Contact_constructorAddress_empty_invalid() {
		String contactID = "9999999999";
		String firstName = "Daniel1234";
		String lastName  = "Loranger12";
		String phoneNumber = "1234567890";
		String address = ""; // invalid

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact(contactID, firstName, lastName, phoneNumber, address);
		});
	}

	@DisplayName("Contact_setFirstName_valid")
	@Test
	void Contact_setFirstName_valid() {
		String contactID = "9999999999";
		String firstName = "Daniel1234";
		String lastName  = "Loranger12";
		String phoneNumber = "1234567890";
		String address = "123 Main Street 12345678901234";

		// Create a valid contact (no exception expected)
		Contact contact = new Contact(contactID, firstName, lastName, phoneNumber, address);

		// Update first name with a valid value
		boolean result = contact.setFirstName("NewFirst");  // valid, <= 10, non-null, non-empty

		assertTrue(result);
		assertEquals("NewFirst", contact.getFirstName());
	}


	@DisplayName("Contact_setFirstName_invalid")
	@Test
	void Contact_setFirstName_invalid() {

		String contactID = "9999999999";
		String firstName = "Daniel1234";
		String lastName  = "Loranger12";
		String phoneNumber = "1234567890";
		String address = "123 Main Street 12345678901234";

		Contact contact = new Contact(contactID, firstName, lastName, phoneNumber, address);

		// too long -> invalid
		boolean result = contact.setFirstName(firstName + "ThisIsTooLong");
		assertFalse(result);                        // should reject invalid name
		assertEquals(firstName, contact.getFirstName()); // unchanged
	}

	@DisplayName("Contact_setLastName_valid")
	@Test
	void Contact_setLastName_valid() {
		String contactID = "9999999999";
		String firstName = "Daniel1234";
		String lastName  = "Loranger12";
		String phoneNumber = "1234567890";
		String address = "123 Main Street 12345678901234";

		Contact contact = new Contact(contactID, firstName, lastName, phoneNumber, address);

		boolean result = contact.setLastName("NewLast");  // valid, <= 10, non-null, non-empty

		assertTrue(result);
		assertEquals("NewLast", contact.getLastName());
	}


	@DisplayName("Contact_setLastName_invalid")
	@Test
	void Contact_setLastName_invalid() {
		String contactID = "9999999999";
		String firstName = "Daniel1234";
		String lastName  = "Loranger12";
		String phoneNumber = "1234567890";
		String address = "123 Main Street 12345678901234";

		Contact contact = new Contact(contactID, firstName, lastName, phoneNumber, address);

		boolean result = contact.setLastName(lastName + "TooLongHere"); // invalid (too long)

		assertFalse(result);
		assertEquals(lastName, contact.getLastName()); // unchanged
	}


	@DisplayName("Contact_setPhoneNumber_valid")
	@Test
	void Contact_setPhoneNumber_valid() {
		String contactID = "9999999999";
		String firstName = "Daniel1234";
		String lastName  = "Loranger12";
		String phoneNumber = "1234567890";
		String address = "123 Main Street 12345678901234";

		Contact contact = new Contact(contactID, firstName, lastName, phoneNumber, address);

		boolean result = contact.setPhoneNumber("0987654321"); // valid: 10 digits

		assertTrue(result);
		assertEquals("0987654321", contact.getPhoneNumber());
	}

	@DisplayName("Contact_setPhoneNumber_invalid")
	@Test
	void Contact_setPhoneNumber_invalid() {
		String contactID = "9999999999";
		String firstName = "Daniel1234";
		String lastName  = "Loranger12";
		String phoneNumber = "1234567890";
		String address = "123 Main Street 12345678901234";

		Contact contact = new Contact(contactID, firstName, lastName, phoneNumber, address);

		boolean result = contact.setPhoneNumber("12345ABCDE"); // invalid: contains letters

		assertFalse(result);
		assertEquals(phoneNumber, contact.getPhoneNumber()); // unchanged
	}

	@DisplayName("Contact_setAddress_valid")
	@Test
	void Contact_setAddress_valid() {
		String contactID = "9999999999";
		String firstName = "Daniel1234";
		String lastName  = "Loranger12";
		String phoneNumber = "1234567890";
		String address = "123 Main Street 12345678901234";

		Contact contact = new Contact(contactID, firstName, lastName, phoneNumber, address);

		boolean result = contact.setAddress("456 Elm Street Apt 12"); // valid <= 30 chars

		assertTrue(result);
		assertEquals("456 Elm Street Apt 12", contact.getAddress());
	}

	@DisplayName("Contact_setAddress_invalid")
	@Test
	void Contact_setAddress_invalid() {
		String contactID = "9999999999";
		String firstName = "Daniel1234";
		String lastName  = "Loranger12";
		String phoneNumber = "1234567890";
		String address = "123 Main Street 12345678901234";

		Contact contact = new Contact(contactID, firstName, lastName, phoneNumber, address);

		String tooLongAddress = "This address is definitely longer than thirty characters";

		boolean result = contact.setAddress(tooLongAddress); // invalid

		assertFalse(result);
		assertEquals(address, contact.getAddress()); // unchanged

	}



}