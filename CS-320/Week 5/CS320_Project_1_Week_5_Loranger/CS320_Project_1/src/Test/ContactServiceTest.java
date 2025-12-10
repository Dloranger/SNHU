package Test;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeEach;

import Contact.Contact;
import Contact.ContactService;

class ContactServiceTest {

    private ContactService service;

    @BeforeEach
    void resetList() {
        ContactService.clearAllContacts();
    }
    
    @BeforeEach
    void setUp() {
        // Fresh service for each test
        service = new ContactService();

        // NOTE: contactList inside ContactService is static,
        // so it will persist across tests.
        // If needed, you can add a helper in ContactService
        // to clear the list for testing, e.g.:
        // ContactService.clearAllContacts();
    }
    

    @DisplayName("ContactService_addNewContact_valid")
    @Test
    void ContactService_addNewContact_valid() {
        String contactID = "9999999999";
        String firstName = "Daniel1234";
        String lastName  = "Loranger12";
        String phoneNumber = "1234567890";
        String address = "123 Main Street 12345678901234";

        Contact contact = new Contact(
            contactID,
            firstName,
            lastName,
            phoneNumber,
            address
        );


        assertTrue(service.addContact(contact));  // addContact should succeed
        assertEquals(contactID, contact.getUniqueID()); // ID is preserved
    }
    
    @DisplayName("ContactService_addNewContact_invalid")
    @Test
    void ContactService_addNewContact_invalid() {
        String contactID = "9999999999";
        String firstName = "Daniel1234";
        String lastName  = "Loranger12";
        String phoneNumber = "1234567890";
        String address = "123 Main Street 12345678901234";

        Contact contact1 = new Contact(
            contactID,
            firstName,
            lastName,
            phoneNumber,
            address
        );

        //first one should pass
        assertTrue(service.addContact(contact1));  // addContact should succeed
        assertEquals(contactID, contact1.getUniqueID()); // ID is preserved
        
        //copy should fail
        Contact contact2 = new Contact(
                contactID,
                firstName,
                lastName,
                phoneNumber,
                address
            );
        
        assertFalse(service.addContact(contact2));  // addContact should fail
    }
    
    @DisplayName("ContactService_addMultipleContact_valid")
    @Test
    void ContactService_addMultpleContact_valid() {
        String contactID1 = "1";
        String contactID2 = "2";
        String firstName = "Daniel1234";
        String lastName  = "Loranger12";
        String phoneNumber = "1234567890";
        String address = "123 Main Street 12345678901234";

        Contact contact1 = new Contact(
            contactID1,
            firstName,
            lastName,
            phoneNumber,
            address
        );

        //first one should pass
        assertTrue(service.addContact(contact1));  // addContact should succeed
        assertEquals(contactID1, contact1.getUniqueID()); // ID is preserved
        
        //second one should also pass
        Contact contact2 = new Contact(
        		contactID2,
                firstName,
                lastName,
                phoneNumber,
                address
            );
        
        assertTrue(service.addContact(contact2));  // addContact should pass
        assertEquals(contactID2, contact2.getUniqueID()); // ID is preserved
        assertEquals(contactID1, contact1.getUniqueID()); // ID is preserved
    }
    
    @DisplayName("ContactService_nextID_valid")
    @Test
    void ContactService_nextID_valid() {
        String contactID1 = "1";
        String contactID2 = "2";
        String firstName = "Daniel1234";
        String lastName  = "Loranger12";
        String phoneNumber = "1234567890";
        String address = "123 Main Street 12345678901234";

        Contact contact1 = new Contact(
            contactID1,
            firstName,
            lastName,
            phoneNumber,
            address
        );

        //first one should pass
        assertTrue(service.addContact(contact1));  // addContact should succeed
        assertEquals(contactID1, contact1.getUniqueID()); // ID is preserved
        
        //second one should also pass
        Contact contact2 = new Contact(
        		contactID2,
                firstName,
                lastName,
                phoneNumber,
                address
            );
        
        assertTrue(service.addContact(contact2));  // addContact should pass
        assertEquals(contactID2, contact2.getUniqueID()); // ID is preserved
        assertEquals(contactID1, contact1.getUniqueID()); // ID is preserved
        
        String newId = service.createContact(
        		firstName,
                lastName,
                phoneNumber,
                address);  // addContact should pass
        
        String newId2 = service.createContact(
        		firstName,
                lastName,
                phoneNumber,
                address);  // addContact should pass
        
        long v1 = Long.parseLong(newId, 36);
        long v2 = Long.parseLong(newId2, 36);
        assertEquals(v1 + 1, v2);
        
    }

    @DisplayName("ContactService_deleteContact_valid")
    @Test
    void ContactService_deleteContact_valid() {
        String contactID = "9999999999";
        String firstName = "Daniel1234";
        String lastName  = "Loranger12";
        String phoneNumber = "1234567890";
        String address = "123 Main Street 12345678901234";

        Contact contact = new Contact(
            contactID,
            firstName,
            lastName,
            phoneNumber,
            address
        );


        assertTrue(service.addContact(contact));  // addContact should succeed
        
        assertTrue(service.deleteContact(contactID)); //contact should be deleted
        //make sure the contact was deleted
        assertFalse(service.deleteContact(contactID)); //contact should not be found
    }
    
    @DisplayName("ContactService_updateContactFirstName_valid")
    @Test
    void ContactService_updateContactFirstName_valid() {
        String contactID = "9999999999";
        String firstName = "Daniel1234";
        String lastName  = "Loranger12";
        String phoneNumber = "1234567890";
        String address = "123 Main Street 12345678901234";

        Contact contact = new Contact(
            contactID,
            firstName,
            lastName,
            phoneNumber,
            address
        );


        assertTrue(service.addContact(contact));  // addContact should succeed
        
        //be sure to obey the character limits
        assertTrue(service.updateContactFirstName(contactID, "newFirst"));
        //make sure the contact was updated
        assertEquals("newFirst", contact.getFirstName()); 
    }
    
    @DisplayName("ContactService_updateContactLastName_valid")
    @Test
    void ContactService_updateContactLastName_valid() {
        String contactID = "9999999999";
        String firstName = "Daniel1234";
        String lastName  = "Loranger12";
        String phoneNumber = "1234567890";
        String address = "123 Main Street 12345678901234";

        Contact contact = new Contact(
            contactID,
            firstName,
            lastName,
            phoneNumber,
            address
        );


        assertTrue(service.addContact(contact));  // addContact should succeed
        
        //be sure to obey the character limits
        assertTrue(service.updateContactLastName(contactID, "newLast"));
        //make sure the contact was updated
        assertEquals("newLast", contact.getLastName());
    }
    
    @DisplayName("ContactService_updateContactPhone_valid")
    @Test
    void ContactService_updateContactPhone_valid() {
        String contactID = "9999999999";
        String firstName = "Daniel1234";
        String lastName  = "Loranger12";
        String phoneNumber = "1234567890";
        String address = "123 Main Street 12345678901234";

        Contact contact = new Contact(
            contactID,
            firstName,
            lastName,
            phoneNumber,
            address
        );


        assertTrue(service.addContact(contact));  // addContact should succeed
        
        //be sure to obey the character limits
        assertTrue(service.updateContactPhone(contactID, "2223334444"));
        //make sure the contact was updated
        assertEquals("2223334444", contact.getPhoneNumber());
    }
    
    @DisplayName("ContactService_updateContactAddress_valid")
    @Test
    void ContactService_updateContactAddress_valid() {
        String contactID = "9999999999";
        String firstName = "Daniel1234";
        String lastName  = "Loranger12";
        String phoneNumber = "1234567890";
        String address = "123 Main Street 12345678901234";

        Contact contact = new Contact(
            contactID,
            firstName,
            lastName,
            phoneNumber,
            address
        );


        assertTrue(service.addContact(contact));  // addContact should succeed
        
        //be sure to obey the character limits
        assertTrue(service.updateContactAddress(contactID, "123 whos ville"));
        //make sure the contact was updated
        assertEquals("123 whos ville", contact.getAddress());
    }
}