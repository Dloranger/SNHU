package Test;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeEach;

import Task.Task;
import Task.TaskService;

class TaskServiceTest {

	private TaskService service;

	@BeforeEach
	void resetList() {
		TaskService.clearAllTasks();
	}

	@BeforeEach
	void setUp() {
		// Fresh service for each test
		service = new TaskService();

		// NOTE: taskList inside TaskService is static,
		// so it will persist across tests.
		// If needed, you can add a helper in TaskService
		// to clear the list for testing, e.g.:
		// TaskService.clearAllTasks();
	}


	@DisplayName("TaskService_addNewTask_valid")
	@Test
	void TaskService_addNewTask_valid() {
		String taskID = "9999999999";
		String name = "validNameUsed";
		String description = "A valid description has been used";

		Task task = new Task(
				taskID,
				name,
				description
				);


		assertTrue(service.addTask(task));  // addTask should succeed
		assertEquals(taskID, task.getUniqueID()); // ID is preserved
	}

	@DisplayName("TaskService_addNewTask_invalid")
	@Test
	void TaskService_addNewTask_invalid() {
		String taskID = "9999999999";
		String name = "validNameUsed";
		String description = "A valid description has been used";

		Task task1 = new Task(
				taskID,
				name,
				description
				);

		//first one should pass
		assertTrue(service.addTask(task1));  // addTask should succeed
		assertEquals(taskID, task1.getUniqueID()); // ID is preserved

		//copy should fail
		Task task2 = new Task(
				taskID,
				name,

				description
				);

		assertFalse(service.addTask(task2));  // addTask should fail
	}

	@DisplayName("TaskService_addMultipleTask_valid")
	@Test
	void TaskService_addMultpleTask_valid() {
		String taskID1 = "1";
		String taskID2 = "2";
		String name = "validNameUsed";
		String description = "A valid description has been used";

		Task task1 = new Task(
				taskID1,
				name,
				description
				);

		//first one should pass
		assertTrue(service.addTask(task1));  // addTask should succeed
		assertEquals(taskID1, task1.getUniqueID()); // ID is preserved

		//second one should also pass
		Task task2 = new Task(
				taskID2,
				name,
				description
				);

		assertTrue(service.addTask(task2));  // addTask should pass
		assertEquals(taskID2, task2.getUniqueID()); // ID is preserved
		assertEquals(taskID1, task1.getUniqueID()); // ID is preserved
	}

	@DisplayName("TaskService_nextID_valid")
	@Test
	void TaskService_nextID_valid() {
		String taskID1 = "1";
		String taskID2 = "2";
		String name = "validNameUsed";
		String description = "A valid description has been used";

		Task task1 = new Task(
				taskID1,
				name,
				description
				);

		//first one should pass
		assertTrue(service.addTask(task1));  // addTask should succeed
		assertEquals(taskID1, task1.getUniqueID()); // ID is preserved

		//second one should also pass
		Task task2 = new Task(
				taskID2,
				name,
				description
				);

		assertTrue(service.addTask(task2));  // addTask should pass
		assertEquals(taskID2, task2.getUniqueID()); // ID is preserved
		assertEquals(taskID1, task1.getUniqueID()); // ID is preserved

		String newId = service.createTask(
				name,
				description);  // addTask should pass

		String newId2 = service.createTask(
				name,
				description);  // addTask should pass

		long v1 = Long.parseLong(newId, 36);
		long v2 = Long.parseLong(newId2, 36);
		assertEquals(v1 + 1, v2);

	}

	@DisplayName("TaskService_deleteTask_valid")
	@Test
	void TaskService_deleteTask_valid() {
		String taskID = "9999999999";
		String name = "validNameUsed";
		String description = "A valid description has been used";

		Task task = new Task(
				taskID,
				name,
				description
				);


		assertTrue(service.addTask(task));  // addTask should succeed

		assertTrue(service.deleteTask(taskID)); //task should be deleted
		//make sure the task was deleted
		assertFalse(service.deleteTask(taskID)); //task should not be found
	}

	@DisplayName("TaskService_updateTaskName_valid")
	@Test
	void TaskService_updateTaskName_valid() {
		String taskID = "9999999999";
		String name = "validNameUsed";
		String description = "A valid description has been used";

		Task task = new Task(
				taskID,
				name,
				description
				);


		assertTrue(service.addTask(task));  // addTask should succeed

		//be sure to obey the character limits
		assertTrue(service.updateTaskName(taskID, "newName"));
		//make sure the task was updated
		assertEquals("newName", task.getName()); 
	}

	@DisplayName("TaskService_updateTaskName_invalid")
	@Test
	void TaskService_updateTaskName_invalid() {
		String taskID = "9999999999";
		String name = "validNameUsed";
		String description = "A valid description has been used";

		Task task = new Task(
				taskID,
				name,
				description
				);


		assertTrue(service.addTask(task));  // addTask should succeed

		//be sure to obey the character limits
		assertFalse(service.updateTaskName(taskID, "invalidNameUsedWithExtraCharacters"));
	}
	
	@DisplayName("TaskService_updateTaskName_invalidID")
	@Test
	void TaskService_updateTaskName_invalidID() {
		String taskID = "9999999999";
		String name = "validNameUsed";
		String description = "A valid description has been used";

		Task task = new Task(
				taskID,
				name,
				description
				);


		assertTrue(service.addTask(task));  // addTask should succeed

		//provide an invalid ID to update
		assertFalse(service.updateTaskName("123", description));
	}


	@DisplayName("TaskService_updateTaskDescription_valid")
	@Test
	void TaskService_updateTaskDescription_valid() {
		String taskID = "9999999999";
		String name = "validNameUsed";
		String description = "A valid description has been used";

		Task task = new Task(
				taskID,
				name,
				description
				);


		assertTrue(service.addTask(task));  // addTask should succeed

		//be sure to obey the character limits
		assertTrue(service.updateTaskDescription(taskID, "new Value Used"));
		//make sure the task was updated
		assertEquals("new Value Used", task.getDescription());
	}


	@DisplayName("TaskService_updateTaskDescription_invalid")
	@Test
	void TaskService_updateTaskDescription_invalid() {
		String taskID = "9999999999";
		String name = "validNameUsed";
		String description = "A valid description has been used";

		Task task = new Task(
				taskID,
				name,
				description
				);


		assertTrue(service.addTask(task));  // addTask should succeed

		//be sure to disobey the character limits
		assertFalse(service.updateTaskDescription(taskID, "An invalid description has been used in this test case"));
	
	}
	
	@DisplayName("TaskService_updateTaskDescription_invalidID")
	@Test
	void TaskService_updateTaskDescriptoin_invalidID() {
		String taskID = "9999999999";
		String name = "validNameUsed";
		String description = "A valid description has been used";

		Task task = new Task(
				taskID,
				name,
				description
				);


		assertTrue(service.addTask(task));  // addTask should succeed

		//provide an invalid ID to update
		assertFalse(service.updateTaskDescription("123", description));
	}
	
}