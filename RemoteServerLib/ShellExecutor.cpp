/****************************************************************************
**
** Copyright (C) 2012 Rawen Software and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Alex Rawen (tekken3mman@gmail.com)
**
** This file is module RemoteServerLibrary.
**
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/


#include <windows.h>
#include "ShellExecutor.h"


ShellExecutor::ShellExecutor(void)
{

}


ShellExecutor::~ShellExecutor(void)
{

}

void ShellExecutor::ExecComm(ICommand* command, IResult* result)
{
	switch(command->getType())
	{

	case COM_EXEC:
		WinExec((LPCSTR)static_cast<ExecCommand*>(command)->getCommand(), SW_SHOW);
		static_cast<ExecResult*>(result)->SetExitCode(0);
		break;

	case COM_DIR:
		static_cast<DirCommand*>(command)->getDir();
		break;

	case COM_DEL:
		static_cast<DelCommand*>(command)->getPath();
		break;

	case COM_SYS_INFO:
		break;

	case COM_DOWNLOAD:
		break;

	case COM_UPLOAD:
		break;

	default:
		break;
	}
}