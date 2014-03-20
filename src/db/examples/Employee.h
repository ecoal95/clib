/*const*/ Model * EMPLOYEE_MODEL;

typedef Object Employee;

void Employee_init() {
	char * fields[] = {"id", "first_name", "last_name", "is_active"};
	EMPLOYEE_MODEL = newModel(fields, 4);
}

void Employee_initialize(Employee * emp, uint id, char * first_name, char * last_name, ushort is_active) {
	Object_initialize(emp, EMPLOYEE_MODEL);

	Object_set_uint(emp, "id", id);
	Object_set_string(emp, "first_name", first_name);
	Object_set_string(emp, "last_name", last_name);
	Object_set_boolean(emp, "is_active", is_active);
}

Employee newEmployee(unsigned id, char * first_name, char * last_name, unsigned short is_active) {
	Employee emp;
	Employee_initialize(&emp, id, first_name, last_name, is_active);
	return emp;
}

unsigned Employee_getId(Employee * e) {
	return Object_get_unsigned(e, "id");
}

char * Employee_getFirstName(Employee * e) {
	return Object_get_string(e, "first_name");
}

void Employee_setFirstName(Employee * e, char * first_name) {
	Object_set_string(e, "first_name", first_name);
}

char * Employee_getLastName(Employee * e) {
	return Object_get_string(e, "last_name");
}

void Employee_setLastName(Employee * e, char * last_name) {
	Object_set_string(e, "last_name", last_name);
}


unsigned short Employee_isActive(Employee * e) {
	return Object_get_boolean(e, "is_active");
}
