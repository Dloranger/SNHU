package Test;

import static org.junit.jupiter.api.Assertions.*;

import java.util.Date;
import java.util.Calendar;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.DisplayName;
import Appointment.AppointmentService;

class AppointmentServiceTest {

    private static Date futureDate;
    static {
        Calendar cal = Calendar.getInstance();
        cal.add(Calendar.DATE, 7);
        futureDate = cal.getTime();
    }

    @DisplayName("AppointmentService_createAppointment_valid")
    @Test
    void AppointmentService_createAppointment_valid() {
        AppointmentService.clearAllAppointments();
        AppointmentService service = new AppointmentService();

        String id = service.createAppointment("valid description", futureDate);

        assertAll(
            () -> assertNotNull(id),
            () -> assertTrue(id.length() <= 10),
            () -> assertEquals(id.toUpperCase(), id)
        );
    }

    @DisplayName("AppointmentService_createAppointment_uniqueIDs")
    @Test
    void AppointmentService_createAppointment_uniqueIDs() {
        AppointmentService.clearAllAppointments();
        AppointmentService service = new AppointmentService();

        String id1 = service.createAppointment("desc1", futureDate);
        String id2 = service.createAppointment("desc2", futureDate);

        assertAll(
            () -> assertNotNull(id1),
            () -> assertNotNull(id2),
            () -> assertNotEquals(id1, id2)
        );
    }

    @DisplayName("AppointmentService_deleteAppointment_valid")
    @Test
    void AppointmentService_deleteAppointment_valid() {
        AppointmentService.clearAllAppointments();
        AppointmentService service = new AppointmentService();

        String id = service.createAppointment("desc", futureDate);
        boolean deleted = service.deleteAppointment(id);

        assertAll(
            () -> assertTrue(deleted),
            () -> assertFalse(service.deleteAppointment(id))
        );
    }

    @DisplayName("AppointmentService_deleteAppointment_invalidID")
    @Test
    void AppointmentService_deleteAppointment_invalidID() {
        AppointmentService.clearAllAppointments();
        AppointmentService service = new AppointmentService();

        boolean result = service.deleteAppointment("BADID");

        assertAll(
            () -> assertFalse(result)
        );
    }

    @DisplayName("AppointmentService_updateAppointmentDate_valid")
    @Test
    void AppointmentService_updateAppointmentDate_valid() {
        AppointmentService.clearAllAppointments();
        AppointmentService service = new AppointmentService();

        String id = service.createAppointment("desc", futureDate);

        Calendar cal = Calendar.getInstance();
        cal.add(Calendar.DATE, 10);
        Date newDate = cal.getTime();

        boolean updated = service.updateAppointmentDate(id, newDate);

        assertAll(
            () -> assertTrue(updated)
        );
    }

    @DisplayName("AppointmentService_updateAppointmentDate_invalid_past")
    @Test
    void AppointmentService_updateAppointmentDate_invalid_past() {
        AppointmentService.clearAllAppointments();
        AppointmentService service = new AppointmentService();

        String id = service.createAppointment("desc", futureDate);

        Calendar cal = Calendar.getInstance();
        cal.add(Calendar.DATE, -5);
        Date pastDate = cal.getTime();

        boolean updated = service.updateAppointmentDate(id, pastDate);

        assertAll(
            () -> assertFalse(updated)
        );
    }

    @DisplayName("AppointmentService_updateAppointmentDescription_valid")
    @Test
    void AppointmentService_updateAppointmentDescription_valid() {
        AppointmentService.clearAllAppointments();
        AppointmentService service = new AppointmentService();

        String id = service.createAppointment("old description", futureDate);

        boolean updated = service.updateAppointmentDescription(id, "new description");

        assertAll(
            () -> assertTrue(updated)
        );
    }

    @DisplayName("AppointmentService_updateAppointmentDescription_invalid_null")
    @Test
    void AppointmentService_updateAppointmentDescription_invalid_null() {
        AppointmentService.clearAllAppointments();
        AppointmentService service = new AppointmentService();

        String id = service.createAppointment("valid description", futureDate);

        boolean updated = service.updateAppointmentDescription(id, null);

        assertAll(
            () -> assertFalse(updated)
        );
    }

    @DisplayName("AppointmentService_updateAppointmentDescription_invalid_tooLong")
    @Test
    void AppointmentService_updateAppointmentDescription_invalid_tooLong() {
        AppointmentService.clearAllAppointments();
        AppointmentService service = new AppointmentService();

        String id = service.createAppointment("valid description", futureDate);

        String tooLong = "123456789012345678901234567890123456789012345678901234567890";

        boolean updated = service.updateAppointmentDescription(id, tooLong);

        assertAll(
            () -> assertFalse(updated)
        );
    }

    @DisplayName("AppointmentService_clearAllAppointments")
    @Test
    void AppointmentService_clearAllAppointments() {
        AppointmentService.clearAllAppointments();
        AppointmentService service = new AppointmentService();

        service.createAppointment("desc1", futureDate);
        service.createAppointment("desc2", futureDate);

        AppointmentService.clearAllAppointments();

        String id = service.createAppointment("desc3", futureDate);

        assertAll(
            () -> assertNotNull(id),
            () -> assertTrue(id.length() <= 10)
        );
    }
}
