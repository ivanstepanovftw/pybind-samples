#include <pybind11/pybind11.h>


int
add(int a, int b)
{
	return a + b;
}


int
sub(int a, int b)
{
	return a - b;
}


namespace py = pybind11;

PYBIND11_PLUGIN(cpp) {
	py::module m("cpp", "sample c++ bindings module");
	m.def("add", &add, "Adds two numbers.");
	m.def("sub", &sub, "Subtracts one number from another.");

	return m.ptr();
}
