#include "jacobi_cpp.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/iostream.h>


    
PYBIND11_MODULE(jacobi_cpp, m) {
    m.doc() = "This module uses the c++ code to solve differential equation using Jacobi method"; // optional mdule docstring

    m.def("test_func", &old_main, "execute old main code");
    using DCMesh = CMesh<double>;
    using DCSolver = CSolver<double>;
    pybind11::class_<DCMesh> (m, "CMesh")
	    .def(pybind11::init<const int &>())
        .def("initialize", &DCMesh::initialize)
        .def("print_all", &DCMesh::print_all)
        .def("print", &DCMesh::print_all)
        .def("step", &DCMesh::step);
    
    pybind11::class_<DCSolver> (m, "CSolver")
        .def(pybind11::init<>())
        .def("jacobi", &DCSolver::jacobi);
}



