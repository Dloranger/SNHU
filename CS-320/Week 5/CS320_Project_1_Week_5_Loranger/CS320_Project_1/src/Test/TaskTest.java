package Test;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;

import Task.Task;

class TaskTest {

	@DisplayName ("Task_constructor_valid")
	@Test
	void Task_constructor_valid() { 
		String taskID = "9999999999";
		String name = "Task_"+taskID;
		String description = "Task_task"+taskID+"_descripton";

		Task Task = new Task(taskID, name, description);
		
		assertEquals(taskID, Task.getUniqueID());
		assertEquals(name, Task.getName());
		assertEquals(description, Task.getDescription());
	}


	@DisplayName ("Task_constructorUniqueID_invalid")
	@Test
	void Task_constructorUniqueID_invalid() { 
		String taskID = "99999999990";
		String name = "Task_"+taskID;
		String description = "Task_task"+taskID+"_descripton";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Task(taskID, name, description);
		});
	}

	@DisplayName ("Task_constructorName_invalid")
	@Test
	void Task_constructorName_invalid() { 
		String taskID = "9999999999";
		String name = "Task_"+taskID+"Task_"+taskID;
		String description = "Task_task"+taskID+"_descripton";
	

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Task(taskID, name, description);
		});
	}

	@DisplayName ("Task_constructorDescription_invalid")
	@Test
	void Task_constructorDescription_invalid() { 
		String taskID = "9999999999";
		String name = "Task_"+taskID;
		String description = "Task_task"+taskID+"_descripton"+"Task_task"+taskID+"_descripton";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Task(taskID, name, description);
		});
	}

	@DisplayName ("Task_updateTaskID_invalid")
	@Test
	void Task_updateTaskID_invalid() {
		String taskID = "9999999999";
		String name = "Task_"+taskID;
		String description = "Task_task"+taskID+"_descripton";

		Task task = new Task(taskID, name, description);

		// Try updating ID (should fail), be sure to use an otherwise valid value
		boolean result = task.setUniqueID("0123456789");

		assertFalse(result);                            // update should not be allowed
		assertEquals(taskID, task.getUniqueID()); // ID should remain unchanged
	}

	@DisplayName("Task_constructorUniqueID_null_invalid")
	@Test
	void Task_constructorUniqueID_null_invalid() {
		String taskID = null;
		String name = "Task_"+taskID;
		String description = "Task_task"+taskID+"_descripton";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Task(taskID, name, description);
		});
	}

	@DisplayName("Task_constructorName_null_invalid")
	@Test
	void Task_constructorName_null_invalid() {
		String taskID = "9999999999";
		String name = null;
		String description = "Task_task"+taskID+"_descripton";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Task(taskID, name,description);
		});
	}

	@DisplayName("Task_constructorName_empty_invalid")
	@Test
	void Task_constructorName_empty_invalid() {
		String taskID = "9999999999";
		String name = "";
		String description = "Task_task"+taskID+"_descripton";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Task(taskID, name,  description);
		});
	}



	@DisplayName("Task_constructorDescription_null_invalid")
	@Test
	void Task_constructorDescription_null_invalid() {
		String taskID = "9999999999";
		String name = "Task_"+taskID;
		String description = null; // invalid

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Task(taskID, name,  description);
		});
	}

	@DisplayName("Task_constructorDescription_empty_invalid")
	@Test
	void Task_constructorDescription_empty_invalid() {
		String taskID = "9999999999";
		String name = "Task_"+taskID;
		String description = "";

		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Task(taskID, name, description);
		});
	}

	@DisplayName("Task_setName_valid")
	@Test
	void Task_setName_valid() {
		String taskID = "9999999999";
		String name = "Task_"+taskID;
		String description = "Task_task"+taskID+"_descripton";

		// Create a valid task (no exception expected)
		Task task = new Task(taskID, name, description);

		// Update name with a valid value
		boolean result = task.setName("NewName");  // valid, <= 10, non-null, non-empty

		assertTrue(result);
		assertEquals("NewName", task.getName());
	}


	@DisplayName("Task_setName_invalid")
	@Test
	void Task_setName_invalid() {

		String taskID = "9999999999";
		String name = "Task_"+taskID;
		String description = "Task_task"+taskID+"_descripton";

		Task task = new Task(taskID, name, description);

		// too long -> invalid
		boolean result = task.setName(name + "ThisIsTooLong");
		assertFalse(result);                        // should reject invalid name
		assertEquals(name, task.getName()); // unchanged
	}

	@DisplayName("Task_setDescription_valid")
	@Test
	void Task_setDescription_valid() {
		String taskID = "9999999999";
		String name = "Task_"+taskID;
		String description = "Task_task"+taskID+"_descripton";

		Task task = new Task(taskID, name, description);

		boolean result = task.setDescription("Description passing"); // valid <= 30 chars

		assertTrue(result);
		assertEquals("Description passing", task.getDescription());
	}

	@DisplayName("Task_setDescription_invalid")
	@Test
	void Task_setDescription_invalid() {
		String taskID = "9999999999";
		String name = "Task_"+taskID;
		String description = "Task_task"+taskID+"_descripton";

		Task task = new Task(taskID, name, description);

		String tooLongDescription = "This description is definitely longer than 50 characters";

		boolean result = task.setDescription(tooLongDescription); // invalid

		assertFalse(result);
		assertEquals(description, task.getDescription()); // unchanged

	}



}