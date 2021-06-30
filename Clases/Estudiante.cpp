#include "Estudiante.h"

Estudiante::Estudiante()
{
}

Estudiante::Estudiante(string nombre, string email, string contrasenia, string urlImgPerfil, string cedula) : Usuario(nombre, email, contrasenia, urlImgPerfil)
{
    this->cedula = cedula;
}

string Estudiante::getCedula() const
{
    return cedula;
}

void Estudiante::setCedula(string)
{
    this->cedula = cedula;
}

DtEstudiante *Estudiante::getDatosUsuario() const
{
    return new DtEstudiante(getNombre(), getEmail(), getContrasenia(), getUrlImgPerfil(), cedula);
}
