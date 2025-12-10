/*
 * Daniel Loranger
 *  CS-320
 */

package Task;

import java.util.List;
import java.util.ArrayList;

public class TaskService {

	// In-memory list to hold Task objects
	private static List<Task> taskList = new ArrayList<Task>();

	// Counter for generating next unique ID
	private static long counter = 0L; 

	/******************** private functions  ******************/
	
	
	// Check if an ID already exists in the Task list
	private static boolean idExists(String id) {
		for (Task t : taskList) {
			if (t.getUniqueID().toUpperCase().equals(id.toUpperCase())) {
				return true;
			}
		}
		return false;
	}

	/******************** public functions  *******************/
	/*
	 * unit test system helper function to reset the tasks list
	 *  
	 */
	public static void clearAllTasks() {
	    taskList.clear();
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
	 *  add Task with field data supplied
	 *  Task ID is automatically generated based on next available
	 *  alphanumeric character
	 *  
	 *  There is a risk of running out of IDs that is not handled ,but
	 *  10^26 is a lot of entries to run out with 
	 *  
	 *  @param name
	 *  @param description
	 *  @return UniqueID
	 *  
	 */  
	public String createTask(String name, String description) {
	    
		String id = getNextUniqueID().toUpperCase();
	    
		Task task = new Task(id.toUpperCase(), name, description);
	    
		addTask(task);
	    
	    return task.getUniqueID().toUpperCase();
	}

	/*
	 *  add Task per Task ID String
	 *  
	 *  @param Task
	 *  @return boolean true = success
	 */
	public boolean addTask(Task Task) {
		// Check if ID already exists
		for (Task t : taskList) {
			if (t.getUniqueID().toUpperCase().equals(Task.getUniqueID().toUpperCase())) {
				return false;   // duplicate ID, do not add
			}
		}

		taskList.add(Task);

		return true;
	}


	/*
	 *  Delete a Task per Task ID String
	 *  
	 *  @param taskID String
	 *  @return boolean true = success
	 *  
	 */
	public boolean deleteTask(String taskID) {
		//increment thru existing Task looking for a match
		for (int i = 0; i < taskList.size(); i++) {
			Task t = taskList.get(i);
			if (t.getUniqueID().toUpperCase().equals(taskID.toUpperCase())) {
				taskList.remove(i);
				return true;  // Task removed
			}
		}

		// Task not found
		return false;
	}


	/*
	 *  update updateTaskName String
	 *  
	 *  @param taskID String
	 *  @param name String
	 *  @return boolean true = success
	 *  
	 */
	public boolean updateTaskName(String taskID, String name) {
		for (Task t : taskList) {
			if (t.getUniqueID().toUpperCase().equals(taskID.toUpperCase())) {
				// rely on Task's validation
				return t.setName(name);
			}
		}

		// Task not found
		return false;
	}

	/*
	 *  update Task per Task Description String
	 *  
	 *  @param taskID String
	 *  @param description String
	 *  @return boolean true = success
	 *  
	 */
	public boolean updateTaskDescription(String taskID, String description) {

		for (Task t : taskList) {
			if (t.getUniqueID().toUpperCase().equals(taskID.toUpperCase())) {
				return t.setDescription(description);
			}
		}

		return false;
	}

} // class TaskService

