// ***********************************************************************
// Assembly         : 
// Author           : nickl
// Created          : 02-03-2017
//
// Last Modified By : nickl
// Last Modified On : 01-16-2017
// ***********************************************************************
// <copyright file="Exception.cpp" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#define _CRT_SECURE_NO_WARNINGS
#include	"Exception.h"
using std::ostream;

/// <summary>
/// Initializes a new instance of the <see cref="Exception"/> class.
/// </summary>
/// TODO Edit XML Comment Template for Exception
Exception::Exception() : m_msg(nullptr)
{}

/// <summary>
/// Finalizes an instance of the <see cref="Exception"/> class.
/// </summary>
/// TODO Edit XML Comment Template for ~Exception
Exception::~Exception()
{
	if (m_msg)
	{
		delete[] m_msg;
		m_msg = nullptr;
	}
}

/// <summary>
/// Initializes a new instance of the <see cref="Exception"/> class.
/// </summary>
/// <param name="msg">The MSG.</param>
/// TODO Edit XML Comment Template for Exception
Exception::Exception(const char * msg) : m_msg(nullptr)
{
	m_msg = new char[strlen(msg) + 1];
	strcpy(m_msg, msg);
}

/// <summary>
/// Initializes a new instance of the <see cref="Exception"/> class.
/// </summary>
/// <param name="cpy">The cpy.</param>
/// TODO Edit XML Comment Template for Exception
Exception::Exception(Exception & cpy)
{
	if (m_msg)
	{
		cpy.m_msg = new char[strlen(m_msg) + 1];
		strcpy(cpy.m_msg, m_msg);
	}

}

/// <summary>
/// Operator=s the specified RHS.
/// </summary>
/// <param name="rhs">The RHS.</param>
/// <returns>Exception &.</returns>
/// TODO Edit XML Comment Template for operator=
Exception & Exception::operator=(const Exception & rhs)
{
	if (this != &rhs)
	{
		m_msg = new char[strlen(m_msg) + 1];
		strcpy(m_msg, rhs.m_msg);
	}

	return *this;
}



/// <summary>
/// Gets the message.
/// </summary>
/// <returns>const char *.</returns>
/// TODO Edit XML Comment Template for getMessage
const char * Exception::getMessage() const
{
	return m_msg ? m_msg : "";
}

/// <summary>
/// Sets the message.
/// </summary>
/// <param name="msg">The MSG.</param>
/// TODO Edit XML Comment Template for setMessage
void Exception::setMessage(const char * msg)
{
	delete[] m_msg;
	m_msg = new char[strlen(msg) + 1];
	strcpy(m_msg, msg);
}

/// <summary>
/// Operators the specified os.
/// </summary>
/// <param name="os">The os.</param>
/// <param name="ex">The ex.</param>
/// <returns>ostream &.</returns>
/// TODO Edit XML Comment Template for operator<<
ostream & operator<<(ostream & os, const Exception & ex)
{
	os << ex.getMessage();
	return os;
}
