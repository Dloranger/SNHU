package Test;

import static org.junit.jupiter.api.Assertions.*;

import java.util.Date;
import java.util.Calendar;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import Appointment.Appointment;

class AppointmentTest {

	// create a future date to use for tests
	private static Date futureDate;
	static {
		Calendar cal = Calendar.getInstance();
		cal.add(Calendar.DATE, 7);
		futureDate = cal.getTime();
	}

	@DisplayName ("Appointment_constructor_valid")
	@Test
	void Appointment_constructor_valid() { 
		String appointmentID = "8888888888";
		Date date = futureDate;
		String description = "valid description";

		Appointment appointment = new Appointment(appointmentID, date, description);

		assertAll(
			() -> assertEquals(appointmentID.toUpperCase(), appointment.getUniqueID()),
			() -> assertEquals(date, appointment.getDate()),
			() -> assertEquals(description, appointment.getDescription())
		);
	}

	@DisplayName ("Appointment_constructorUniqueID_invalid")
	@Test
	void Appointment_constructorUniqueID_invalid() { 
		String appointmentID = "88888888888";
		Date date = futureDate;
		String description = "valid description";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Appointment(appointmentID, date, description);
		});
	}

	@DisplayName ("Appointment_constructorUniqueID_null_invalid")
	@Test
	void Appointment_constructorUniqueID_null_invalid() {
		String appointmentID = null;
		Date date = futureDate;
		String description = "valid description";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Appointment(appointmentID, date, description);
		});
	}

	@DisplayName ("Appointment_constructor_date_invalid")
	@Test
	void Appointment_constructor_date_invalid() {
		String appointmentID = "8888888888";
		Calendar cal = Calendar.getInstance();
		cal.add(Calendar.DATE, -5);
		Date pastdate = cal.getTime();
		String description = "valid description";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Appointment(appointmentID, pastdate, description);
		});
	}

	@DisplayName ("Appointment_constructor_description_null_invalid")
	@Test
	void Appointment_constructor_description_null_invalid() {
		String appointmentID = "8888888888";
		Date date = futureDate;
		String description = null;

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Appointment(appointmentID, date, description);
		});
	}

	@DisplayName ("Appointment_constructor_description_empty_invalid")
	@Test
	void Appointment_constructor_description_empty_invalid() {
		String appointmentID = "8888888888";
		Date date = futureDate;
		String description = "";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Appointment(appointmentID, date, description);
		});
	}

	@DisplayName ("Appointment_constructor_description_tooLong_invalid")
	@Test
	void Appointment_constructor_description_tooLong_invalid() {
		String appointmentID = "8888888888";
		Date date = futureDate;
		String tooLongDescription = "This string is definitely more than fifty characters long and invalid";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Appointment(appointmentID, date, tooLongDescription);
		});
	}

	@DisplayName ("Appointment_date_invalid")
	@Test
	void Appointment_date_invalid() {
		String appointmentID = "8888888888";
		Date date = futureDate;
		String description = "valid description";

		Appointment appointment = new Appointment(appointmentID, date, description);

		Calendar cal = Calendar.getInstance();
		cal.add(Calendar.DATE, -5);
		Date pastdate = cal.getTime();

		boolean result = appointment.setDate(pastdate);

		assertAll(
			() -> assertFalse(result),
			() -> assertEquals(date, appointment.getDate())
		);
	}

	@DisplayName ("Appointment_updateAppointmentID_invalid")
	@Test
	void Appointment_updateAppointmentID_invalid() {
		String appointmentID = "8888888888";
		Date date = futureDate;
		String description = "valid description";

		Appointment appointment = new Appointment(appointmentID, date, description);

		boolean result = appointment.setUniqueID("8888888887");

		assertAll(
			() -> assertFalse(result),
			() -> assertEquals(appointmentID.toUpperCase(), appointment.getUniqueID())
		);
	}

	@DisplayName ("Appointment_setDescription_valid")
	@Test
	void Appointment_setDescription_valid() {
		String appointmentID = "8888888888";
		Date date = futureDate;
		String description = "valid description";

		Appointment appointment = new Appointment(appointmentID, date, description);

		boolean result = appointment.setDescription("Appointment Description");

		assertAll(
			() -> assertTrue(result),
			() -> assertEquals("Appointment Description", appointment.getDescription())
		);
	}

	@DisplayName ("Appointment_setDescription_invalid")
	@Test
	void Appointment_setDescription_invalid() {
		String appointmentID = "8888888888";
		Date date = futureDate;
		String description = "valid description";

		Appointment appointment = new Appointment(appointmentID, date, description);

		String tooLongDescription = "This description is definitely longer than fifty characters";

		boolean result = appointment.setDescription(tooLongDescription);

		assertAll(
			() -> assertFalse(result),
			() -> assertEquals(description, appointment.getDescription())
		);
	}

	@DisplayName ("Appointment_setDescription_null_invalid")
	@Test
	void Appointment_setDescription_null_invalid() {
		String appointmentID = "8888888888";
		Date date = futureDate;
		String description = "valid description";

		Appointment appointment = new Appointment(appointmentID, date, description);

		boolean result = appointment.setDescription(null);

		assertAll(
			() -> assertFalse(result),
			() -> assertEquals(description, appointment.getDescription())
		);
	}

	@DisplayName ("Appointment_setDescription_empty_invalid")
	@Test
	void Appointment_setDescription_empty_invalid() {
		String appointmentID = "8888888888";
		Date date = futureDate;
		String description = "valid description";

		Appointment appointment = new Appointment(appointmentID, date, description);

		boolean result = appointment.setDescription("");

		assertAll(
			() -> assertFalse(result),
			() -> assertEquals(description, appointment.getDescription())
		);
	}

	@DisplayName ("Appointment_constructorID_valid")
	@Test
	void Appointment_constructorID_valid() {
		String appointmentID = "8888888888";
		Date date = futureDate;
		String description = "valid description";

		Appointment appointment = new Appointment(appointmentID, date, description);

		assertAll(
			() -> assertEquals(appointmentID.toUpperCase(), appointment.getUniqueID())
		);
	}

	@DisplayName ("Appointment_description_valid")
	@Test
	void Appointment_description_valid() {
		String appointmentID = "8888888888";
		Date date = futureDate;
		String description = "12345678901234567890123456789012345678901234567890";

		assertAll(
			() -> assertEquals(50, description.length())
		);

		Appointment appointment = new Appointment(appointmentID, date, description);

		assertAll(
			() -> assertEquals(description, appointment.getDescription())
		);
	}
}
