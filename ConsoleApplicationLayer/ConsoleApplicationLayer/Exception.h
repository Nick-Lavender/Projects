// ***********************************************************************
// Assembly         : 
// Author           : nickl
// Created          : 02-03-2017
//
// Last Modified By : nickl
// Last Modified On : 02-04-2017
// ***********************************************************************
// <copyright file="Exception.h" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#pragma once 
#include <iostream>
using std::ostream;

/// <summary>
/// Class Exception.
/// </summary>
/// TODO Edit XML Comment Template for Exception
class Exception
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Exception"/> class.
	/// </summary>
	/// TODO Edit XML Comment Template for Exception
	Exception();
	/// <summary>
	/// Finalizes an instance of the <see cref="Exception"/> class.
	/// </summary>
	/// TODO Edit XML Comment Template for ~Exception
	~Exception();
	/// <summary>
	/// Initializes a new instance of the <see cref="Exception"/> class.
	/// </summary>
	/// <param name="msg">The MSG.</param>
	/// TODO Edit XML Comment Template for Exception
	Exception(const char * msg);
	/// <summary>
	/// Initializes a new instance of the <see cref="Exception"/> class.
	/// </summary>
	/// <param name="cpy">The cpy.</param>
	/// TODO Edit XML Comment Template for Exception
	Exception(Exception & cpy);
	/// <summary>
	/// Operator=s the specified RHS.
	/// </summary>
	/// <param name="rhs">The RHS.</param>
	/// <returns>Exception &.</returns>
	/// TODO Edit XML Comment Template for operator=
	Exception& operator=(const Exception& rhs);

	friend ostream& operator<<(ostream &os, const Exception &ex);

	/// <summary>
	/// Gets the message.
	/// </summary>
	/// <returns>const char *.</returns>
	/// TODO Edit XML Comment Template for getMessage
	const char* getMessage()const;
	/// <summary>
	/// Sets the message.
	/// </summary>
	/// <param name="msg">The MSG.</param>
	/// TODO Edit XML Comment Template for setMessage
	void setMessage(const char* msg);
private:
	/// <summary>
	/// The m MSG
	/// </summary>
	/// TODO Edit XML Comment Template for m_msg
	char* m_msg = nullptr;
}; 


