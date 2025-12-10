/*
 * Daniel Loranger
 * CS-320
 */

package Appointment;

import java.util.List;
import java.util.ArrayList;

public class AppointmentService {

    // In-memory list to hold Appointment objects
    private static List<Appointment> appointmentList = new ArrayList<Appointment>();

    // Counter for generating next unique ID
    private static long counter = 0L;

    /******************** private functions  *******************/

    /*
     * helper - checks if unique ID exists
     * @param id String <= 10 chars
     * @return bool true = exists
     */
    private static boolean idExists(String id) {
        String upper = id.toUpperCase();
        for (int i = 0; i < appointmentList.size(); i++) {
            if (appointmentList.get(i).getUniqueID().equals(upper)) {
                return true;
            }
        }
        return false;
    }

    /*
     * helper - Adds appointment to list if unique ID is valid
     * @param appointment Appointment
     * @return bool true = success
     */
    private boolean addAppointment(Appointment appointment) {
        if (idExists(appointment.getUniqueID())) {
            return false;
        }
        appointmentList.add(appointment);
        return true;
    }

    /*
     * helper - creates appointment uniqueID
     * @return uniqueID String <= 10 chars
     */
    private static String getNextUniqueID() {
        while (true) {
            counter++;
            String id = Long.toString(counter, 36).toUpperCase();
            if (id.length() > 10) {
                id = id.substring(id.length() - 10);
            }
            if (!idExists(id)) {
                return id;
            }
        }
    }

    /******************** public functions  *******************/

    // Reset the appointment list (unit test helper)
    public static void clearAllAppointments() {
        appointmentList.clear();
        counter = 0L;
    }

    /*
     * Creator - Creates a new appointment
     * @param description String <= 50 chars
     * @param date Date in the future
     * @return uniqueID String
     */
    public String createAppointment(String description, java.util.Date date) {
        Appointment appointment = new Appointment(getNextUniqueID(), date, description);
        addAppointment(appointment);
        return appointment.getUniqueID();
    }

    /*
     * Deleter - deletes appointment from list
     * @param appointmentID String <= 10 chars
     * @return bool true = success
     */
    public boolean deleteAppointment(String appointmentID) {
        String upper = appointmentID.toUpperCase();
        for (int i = 0; i < appointmentList.size(); i++) {
            if (appointmentList.get(i).getUniqueID().equals(upper)) {
                appointmentList.remove(i);
                return true;
            }
        }
        return false;
    }

    /*
     * setter - Updates Appointment date
     * @param appointmentID String
     * @param date Date
     * @return bool true = success
     */
    public boolean updateAppointmentDate(String appointmentID, java.util.Date date) {
        String upper = appointmentID.toUpperCase();
        for (int i = 0; i < appointmentList.size(); i++) {
            if (appointmentList.get(i).getUniqueID().equals(upper)) {
                return appointmentList.get(i).setDate(date);
            }
        }
        return false;
    }

    /*
     * setter - Updates Appointment description
     * @param appointmentID String
     * @param description String <= 50 chars
     * @return bool true = success
     */
    public boolean updateAppointmentDescription(String appointmentID, String description) {
        String upper = appointmentID.toUpperCase();
        for (int i = 0; i < appointmentList.size(); i++) {
            if (appointmentList.get(i).getUniqueID().equals(upper)) {
                return appointmentList.get(i).setDescription(description);
            }
        }
        return false;
    }
}
