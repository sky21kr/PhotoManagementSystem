#pragma once
#include"Application.h"
// ���α׷� ����
void Application::Run()
{

	if( login() == false )	// �α��� ���н�
	{
		return;
	}

	// �α��� ������

	while(1)
	{
		m_Command = GetCommand();

		if(cin.fail())
		{
			cin.clear();
			cin.ignore(1000,'\n');
		}

		switch(m_Command)
		{
		case 1:	
			addFolderInterface();		// ���� ������ ���� �߰�
			break;
		case 2:	
			addPhotoInterface();		// ���� ������ ���� �߰�
			break;
		case 3:	
			deleteFolderInterface();	// ���� ������ ���� ����
			break;
		case 4:	
			deletePhotoInterface();		// ���� ������ ���� ����
			break;
		case 5:
			ModifyFoldrName();			// ���� ������ ���� �̸� ����
			break;
		case 6:
			ModifyPhoto();				// ���� ������ ���� ����
			break;
		case 7:
			cutoff();	// ���� �߶󳻱�
			break;
		case 8:
			paste();	// ���� �ٿ��ֱ�
			break;
		case 9:
			hidePhoto();	// ���� ����
			break;
		case 10:
			un_hidePhoto();	// ���� ��������
			break;
		case 11:
			bookmarkAdd();	// ���ã�� �߰�
			break;
		case 12:
			bookmarkDelete();	// ���ã�� ����
			break;
		case 13:
			bookmarkPrint();	// ���ã�� ��� ���
			break;
		case 14:
			displayCurFolderByName();	//	���� ������ ���� �̸������� ���
			break;
		case 15:
			print_hidePhoto();	// ���� ���� ���
			break;
		case 16:
			FindNDisplayFolder();		// ���� ������ ���� �˻�
			break;
		case 17:
			FindNDisplayPhoto();		// ���� ������ ���� �˻�
			break;
		case 18:
			moveCurFolder();	// ���� �̵�
			break;
		case 19:
			backFolder();		// �ڷΰ���
			break;
		case 20:
			changePassword();	// ��� ��ȣ ����
			break;
		case 0:
			WriteDataToFile();	// ���� �� ������ ����
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// Ŀ�ǵ� �����ְ� Ű����κ��� Ű �Է¹ޱ�
int Application::GetCommand()
{
	system("cls");
	int command;
	cout << endl;
	cout << "\t-------------------------" << endl << endl;
	cout << "\t ���� ���� : " << curFolder->GetName() << endl << endl;
	cout << "\t----- Command -----------" << endl;
	cout << "\t   1 : ���� �߰�" << endl;
	cout << "\t   2 : ���� �߰�" << endl;
	cout << "\t   3 : ���� ����" << endl;
	cout << "\t   4 : ���� ����" << endl;
	cout << "\t   5 : ���� ����" << endl;
	cout << "\t   6 : ���� ����" << endl;
	cout << "\t   7 : ���� �߶󳻱�" << endl;
	cout << "\t   8 : ���� �ٿ��ֱ�" << endl;
	cout << "\t   9 : ���� ����" << endl;
	cout << "\t  10 : ���� ��������" << endl;
	cout << "\t  11 : ���ã�� �߰�" << endl;
	cout << "\t  12 : ���ã�⿡�� �ֱ� ���� ����" << endl;
	cout << "\t  13 : ���ã�� ��� ���" << endl;
	cout << "\t  14 : ���� ������ ������ �̸������� ���" << endl;
	cout << "\t  15 : ���� ������ ���� ������ ���" << endl;
	cout << "\t  16 : ������ �̸����� �˻�" << endl;
	cout << "\t  17 : ������ �̸����� �˻�" << endl;
	cout << "\t  18 : ���� ���� �̵�" << endl;
	cout << "\t  19 : �ڷΰ���" << endl;
	cout << "\t  20 : ��й�ȣ ����" << endl;
	cout << "\t   0 : ���� �� ����" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	system("cls");

	return command;
}

// ���� ������ ���� �߰�
void Application::addFolderInterface()
{
	cout << endl << endl;
	cout << "\t----- ���� �߰� -----" << endl;
	curFolder->addFolder();
}

// ���� ������ ���� �߰�
void Application::addPhotoInterface()
{
	cout << endl << endl;
	cout << "\t----- ���� �߰� -----" << endl;
	curFolder->addPhoto();
}

// ���� ������ ���� ����
void Application::deleteFolderInterface()
{
	cout << endl << endl;
	cout << "\t----- ���� ���� -----" << endl;
	curFolder->deleteFolder();
	cout << endl;
	system("pause");
}

// ���� ������ ���� ����
void Application::deletePhotoInterface()
{
	cout << endl << endl;
	cout << "\t----- ���� ���� -----" << endl;
	curFolder->deletePhoto();
	cout << endl << "\t";
	system("pause");
}

//���� �̵�
void Application::moveCurFolder()
{
	cout << endl << endl;
	cout << "\t----- ���� �̵� -----" << endl;
	
	folderType* folderaddress = curFolder->moveFolder(); // �̸� �Ȱ��� ���� �ּҸ��� ��ã���� NULL ����
	if( folderaddress != NULL )	// ������ ã����
	{
		folderStack.Push(curFolder);	// ���� �̵��� ���� ������ ���ÿ� �߰�
		curFolder = folderaddress;	// ���� ���� �̵�
		cout << "\t������ �̵��Ͽ����ϴ�." << endl;
	}
	else
		cout << "\t���� �̵��� �����߽��ϴ�." << endl;

	cout << endl << "\t";
	system("pause");
}


//���� ������ ��ο� ���� �̸������� ���
void Application::displayCurFolderByName()
{
	cout << endl << endl;
	cout << "\t----- ���� ������ ������ ���� ��� -----" << endl;
	curFolder->displayFolderByName();

	cout << endl << "\t";
	system("pause");
}


// �ڷΰ���
void Application::backFolder()
{
	cout << endl << endl;
	cout << "\t----- �ڷ� ���� -----" << endl;
	if( folderStack.IsEmpty() ) // �ֻ��� ������ ���
	{
		cout << "\t�̹� �ֻ��� �����Դϴ�." << endl;
	}
	else	// �ֻ��� ������ �ƴҰ��
	{
		folderStack.Pop(curFolder);	// �������ÿ��� ������ ���� ���� �ٲ�

		cout << "\t������ �̵��߽��ϴ�." << endl;
	}

	cout << endl << "\t";
	system("pause");
}

// ������ �̸����� �˻��� Ű���尡 ���ԵǸ� �����
void Application::FindNDisplayFolder()
{

	cout << endl << endl;
	cout << "\t----- ���� �˻� -----" << endl;
	string command;

	cout << "\t1. ���� ��ü���� �˻�" << endl;
	cout << "\t2. ���� ���������� �˻�" << endl;
	cout << "\t-> ";
	cin >> command;
	if(command == "1")	// ���� ��ü���� �˻�
	{
		folderType folder;
		folder.setfoldernamefromKB();
		photoalbum.FindFolderAll(folder);

	}
	else if(command == "2")	// ���� ���������� �˻�
	{
		curFolder->FindFolder();
	}
	else
		cout << "\t�߸��� �Է��Դϴ�." << endl;

	cout << endl << "\t";
	system("pause");
}

// ������ �̸����� �˻���
void Application::FindNDisplayPhoto()
{
	cout << endl << endl;
	cout << "\t----- ���� �˻� -----" << endl;
	string command;

	cout << "\t1. ���� ��ü���� �˻�" << endl;
	cout << "\t2. ���� ���������� �˻�" << endl;
	cout << "\t-> ";
	cin >> command;
	if(command == "1")	// ���� ��ü���� �˻�
	{
		photoType photo;
		photo.setphotoNameKB();
		photoalbum.FindPhotoAll(photo);
	}
	else if(command == "2")	// ���� �������� �˻�
	{
		curFolder->FindPhoto();
	}
	else
		cout << "\t�߸��� �Է��Դϴ�." << endl;

	cout << endl << "\t";
	system("pause");
}

// ������ ������������ ���� ��ũ���ͷ� ������ ����
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// �б����� ���� ����
	
	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_InFile)	return 0;
	else	return 1;
}


// ������ �������� ���� ��ũ���ͷ� ������ ����
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// �������� ���� ����
	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_OutFile)	return 0;
	else	return 1;
}

// �б���� ������ ���� ������ ��� �����͸� ������ �� �����͸� ����Ʈ�� �ִ´�
int Application::ReadDataFromFile()
{

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenInFile("PhotoAlbum.txt"))
	{
		cout << "\t������ �� �� �����ϴ�." << endl;
		return 0;
	}

	photoalbum.ReadFolder(m_InFile,bookmark);	// ���� �о����

	curFolder = &photoalbum;	// ���� ���� ���� ����������

	m_InFile.close();	// ���� �ݱ�

	return 1;
}

// ������� ������ ���� ��� �����͸� �� ���Ͽ� ����
int Application::WriteDataToFile()
{
	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenOutFile("PhotoAlbum.txt"))
	{
		cout <<"\t�����߽��ϴ�." << endl;
		return 0;
	}


	photoalbum.WriteFolder(m_OutFile);	// ���� ���Ͽ� ����

	m_OutFile.close();	// ���� �ݱ�

	return 1;
}

// ���� �̸� �����ϱ�
void Application ::ModifyFoldrName()
{
	cout << endl << endl;
	cout << "\t----- ���� ���� -----" << endl;
	curFolder->ModifyFolderName();
	cout << endl;
	system("pause");
}

// ���� ���� �����ϱ�
void Application ::ModifyPhoto()
{
	cout << endl << endl;
	cout << "\t----- ���� ���� -----" << endl;
	curFolder->ModifyPhoto();
	cout << endl;
	system("pause");
}

// ��й�ȣ ����
void Application::changePassword()
{
	cout << endl << endl;
	cout << "\t----- ��й�ȣ ���� -----" << endl;

	if(!OpenInFile(("login.txt")))
	{
		cout << "\t���� ����! login.txt Ȯ�ιٶ�." << endl;
		cout << endl << "\t";
		system("pause");
		return;
	}

	string password;	// ���� ��й�ȣ

	m_InFile >> password;

	m_InFile.close();

	string m_password;	// ����ڰ� �Է��� ��й�ȣ
	string newpassword;	// �ٲ� ��й�ȣ
	string repassword;	// ��й�ȣ Ȯ��

	cout << "\t������ ��й�ȣ �Է� : ";
	cin >> m_password;
	
	if( m_password == password )	// ���� ��й�ȣ�� ����ڰ� �Է��� ��й�ȣ�� ������
	{
		if(!OpenOutFile(("login.txt")))
		{
			cout << "\t���� ����! login.txt Ȯ�ιٶ�." << endl;
			cout << endl << "\t";
			system("pause");
			return;
		}

		cout << endl << "\t�� ��й�ȣ �Է� : ";
		cin >> newpassword;

		cout << endl << "\t�ѹ� �� �Է����ּ��� : ";
		cin >> repassword;

		if( newpassword == repassword )	// �� ��й�ȣ�� �ٽ� �Է��� ��й�ȣ�� ���� ��
		{
			m_OutFile << newpassword;
			cout << "\t��й�ȣ ���� �Ϸ�!" << endl;
			m_OutFile.close();

			cout << endl << "\t";
			system("pause");
			return;
		}
		
		cout << endl << "\t��й�ȣ ���� ����" << endl;	// �� ��й�ȣ�� �ٽ� �Է��� ��й�ȣ�� �ٸ� ��
		m_OutFile << password;
		m_OutFile.close();
	}
	else	// ��й�ȣ�� Ʋ���� ��
	{
		cout << "\t��й�ȣ�� ���� �ʽ��ϴ�." << endl;
		m_OutFile.close();
	}

	cout << endl << "\t";
	system("pause");
}

// �α��� �Ѵ�.
bool Application ::login()
{
	if(!OpenInFile(("login.txt")))
	{
		cout << "\t���� ����! login.txt Ȯ�ιٶ�." << endl;
		return false;
	}

	string password;
	string m_password;
	m_InFile >> password;

	while(1)
	{
		cout << endl << endl << endl << endl;
		cout << "\t\t\tPhotoManagementSystem" << endl << endl << endl << endl;

		if( password == "1234" )	// ��й�ȣ�� 1234�϶� �˷��ش�.
		{
			cout << "\t�ʱ� ��й�ȣ - 1234" << endl << endl << endl;
		}

		cout << "\t\t Password : ";
		cin >> m_password;

		if( password != m_password )	// �α��� ���н�
		{
			system("cls");
			continue;
		}
		else	// �α��� ������
		{
			system("cls");
			m_InFile.close();
			ReadDataFromFile();	// �����͸� �ҷ���
			return true;
		}
	}
}

// ���ã�� �߰�
void Application::bookmarkAdd()
{
	cout << endl << endl;
	cout << "\t----- ���ã�� �߰� -----" << endl;
	curFolder->bookmarkAdd_F(bookmark);
	cout << endl << "\t";
	system("pause");
}

// ���ã�� ����
void Application::bookmarkDelete()
{
	cout << endl << endl;
	cout << "\t----- ���� �ֱ� ��¥ ���ã�� ���� -----" << endl;
	photoType* photo;
	if(bookmark.Get(photo) == NULL )
	{
		cout << "\t������ �����߽��ϴ�." << endl;
	}
	else
	{
		photo->setbook(0);
		cout << "\t������ �����߽��ϴ�." << endl;
		
	}

	cout << endl << "\t";
	system("pause");
}

// ���ã�� ��� ���
void Application::bookmarkPrint()
{
	cout << endl << endl;
	cout << "\t----- ���ã�� ��� ��� -----" << endl;
	bookmark.PrintHeap();

	cout << endl << "\t";
	system("pause");
}

// ���� �߶󳻱�
void Application::cutoff()
{
	cout << endl << endl;
	cout << "\t----- ���� �߶󳻱� -----" << endl;
	if( Is_tempPhoto == true )
	{
		cout << "\t�̹� �߶���� ������ �ֽ��ϴ�. ���� ó�����ּ���" << endl;
	}
	else if( curFolder->cutoff_F(tempPhoto) == true )
		Is_tempPhoto = true;

	cout << endl << "\t";
	system("pause");
}

// ���� �ٿ��ֱ�
void Application::paste()
{

	cout << endl << endl;
	if( Is_tempPhoto == false )
	{
		cout <<"\t�߶���� ������ �����ϴ�." << endl;
	}
	else
	{
		cout << "\t----- ���� �ٿ��ֱ� -----" << endl;
		if( curFolder->paste_F(tempPhoto) == true )
			Is_tempPhoto = false;
	}

	cout << endl << "\t";
	system("pause");
}

// ���� �����
void Application::hidePhoto()
{
	cout << endl << endl;
	cout << "\t----- ���� ����� -----" << endl;
	curFolder->hidePhoto_F();

	cout << endl << "\t";
	system("pause");
}

// ���� ���� ����
void Application::un_hidePhoto()
{
	cout << endl << endl;
	cout << "\t----- ���� ���� ���� -----" << endl;
	curFolder->un_hidePhoto_F();
	cout << endl << "\t";
	system("pause");
}

// ���� ������ ���� ������ ���
void Application::print_hidePhoto()
{
	cout << endl << endl;
	cout << "\t----- ���� ������ ���� ���� ��� -----" << endl;
	curFolder->print_hidePhoto_F();

	cout << endl << "\t";
	system("pause");
}