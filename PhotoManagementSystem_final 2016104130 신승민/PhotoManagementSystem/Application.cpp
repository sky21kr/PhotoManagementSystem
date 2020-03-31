#pragma once
#include"Application.h"
// 프로그램 가동
void Application::Run()
{

	if( login() == false )	// 로그인 실패시
	{
		return;
	}

	// 로그인 성공시

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
			addFolderInterface();		// 현재 폴더에 폴더 추가
			break;
		case 2:	
			addPhotoInterface();		// 현재 폴더에 사진 추가
			break;
		case 3:	
			deleteFolderInterface();	// 현재 폴더의 폴더 삭제
			break;
		case 4:	
			deletePhotoInterface();		// 현재 폴더의 사진 삭제
			break;
		case 5:
			ModifyFoldrName();			// 현재 폴더의 폴더 이름 수정
			break;
		case 6:
			ModifyPhoto();				// 현재 폴더의 사진 수정
			break;
		case 7:
			cutoff();	// 사진 잘라내기
			break;
		case 8:
			paste();	// 사진 붙여넣기
			break;
		case 9:
			hidePhoto();	// 사진 숨김
			break;
		case 10:
			un_hidePhoto();	// 사진 숨김해제
			break;
		case 11:
			bookmarkAdd();	// 즐겨찾기 추가
			break;
		case 12:
			bookmarkDelete();	// 즐겨찾기 삭제
			break;
		case 13:
			bookmarkPrint();	// 즐겨찾기 목록 출력
			break;
		case 14:
			displayCurFolderByName();	//	현재 폴더의 파일 이름순으로 출력
			break;
		case 15:
			print_hidePhoto();	// 숨긴 사진 출력
			break;
		case 16:
			FindNDisplayFolder();		// 현재 폴더의 폴더 검색
			break;
		case 17:
			FindNDisplayPhoto();		// 현재 폴더의 사진 검색
			break;
		case 18:
			moveCurFolder();	// 폴더 이동
			break;
		case 19:
			backFolder();		// 뒤로가기
			break;
		case 20:
			changePassword();	// 비밀 번호 변경
			break;
		case 0:
			WriteDataToFile();	// 종료 및 데이터 쓰기
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

// 커맨드 보여주고 키보드로부터 키 입력받기
int Application::GetCommand()
{
	system("cls");
	int command;
	cout << endl;
	cout << "\t-------------------------" << endl << endl;
	cout << "\t 현재 폴더 : " << curFolder->GetName() << endl << endl;
	cout << "\t----- Command -----------" << endl;
	cout << "\t   1 : 폴더 추가" << endl;
	cout << "\t   2 : 사진 추가" << endl;
	cout << "\t   3 : 폴더 삭제" << endl;
	cout << "\t   4 : 사진 삭제" << endl;
	cout << "\t   5 : 폴더 수정" << endl;
	cout << "\t   6 : 사진 수정" << endl;
	cout << "\t   7 : 사진 잘라내기" << endl;
	cout << "\t   8 : 사진 붙여넣기" << endl;
	cout << "\t   9 : 사진 숨김" << endl;
	cout << "\t  10 : 사진 숨김해제" << endl;
	cout << "\t  11 : 즐겨찾기 추가" << endl;
	cout << "\t  12 : 즐겨찾기에서 최근 사진 삭제" << endl;
	cout << "\t  13 : 즐겨찾기 목록 출력" << endl;
	cout << "\t  14 : 현재 폴더의 내용을 이름순으로 출력" << endl;
	cout << "\t  15 : 현재 폴더의 숨긴 사진을 출력" << endl;
	cout << "\t  16 : 폴더를 이름으로 검색" << endl;
	cout << "\t  17 : 사진을 이름으로 검색" << endl;
	cout << "\t  18 : 현재 폴더 이동" << endl;
	cout << "\t  19 : 뒤로가기" << endl;
	cout << "\t  20 : 비밀번호 변경" << endl;
	cout << "\t   0 : 종료 및 저장" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	system("cls");

	return command;
}

// 현재 폴더에 폴더 추가
void Application::addFolderInterface()
{
	cout << endl << endl;
	cout << "\t----- 폴더 추가 -----" << endl;
	curFolder->addFolder();
}

// 현재 폴더에 사진 추가
void Application::addPhotoInterface()
{
	cout << endl << endl;
	cout << "\t----- 사진 추가 -----" << endl;
	curFolder->addPhoto();
}

// 현재 폴더의 폴더 삭제
void Application::deleteFolderInterface()
{
	cout << endl << endl;
	cout << "\t----- 폴더 삭제 -----" << endl;
	curFolder->deleteFolder();
	cout << endl;
	system("pause");
}

// 현재 폴더의 사진 삭제
void Application::deletePhotoInterface()
{
	cout << endl << endl;
	cout << "\t----- 사진 삭제 -----" << endl;
	curFolder->deletePhoto();
	cout << endl << "\t";
	system("pause");
}

//폴더 이동
void Application::moveCurFolder()
{
	cout << endl << endl;
	cout << "\t----- 폴더 이동 -----" << endl;
	
	folderType* folderaddress = curFolder->moveFolder(); // 이름 똑같은 폴더 주소리턴 못찾으면 NULL 리턴
	if( folderaddress != NULL )	// 폴더를 찾으면
	{
		folderStack.Push(curFolder);	// 폴더 이동시 현재 폴더를 스택에 추가
		curFolder = folderaddress;	// 현재 폴더 이동
		cout << "\t폴더를 이동하였습니다." << endl;
	}
	else
		cout << "\t폴더 이동에 실패했습니다." << endl;

	cout << endl << "\t";
	system("pause");
}


//현재 폴더의 경로와 파일 이름순으로 출력
void Application::displayCurFolderByName()
{
	cout << endl << endl;
	cout << "\t----- 현재 폴더의 폴더와 사진 출력 -----" << endl;
	curFolder->displayFolderByName();

	cout << endl << "\t";
	system("pause");
}


// 뒤로가기
void Application::backFolder()
{
	cout << endl << endl;
	cout << "\t----- 뒤로 가기 -----" << endl;
	if( folderStack.IsEmpty() ) // 최상위 폴더일 경우
	{
		cout << "\t이미 최상위 폴더입니다." << endl;
	}
	else	// 최상위 폴더가 아닐경우
	{
		folderStack.Pop(curFolder);	// 폴더스택에서 꺼내서 현재 폴더 바꿈

		cout << "\t폴더를 이동했습니다." << endl;
	}

	cout << endl << "\t";
	system("pause");
}

// 폴더를 이름으로 검색함 키워드가 포함되면 출력함
void Application::FindNDisplayFolder()
{

	cout << endl << endl;
	cout << "\t----- 폴더 검색 -----" << endl;
	string command;

	cout << "\t1. 폴더 전체에서 검색" << endl;
	cout << "\t2. 현재 폴더에서만 검색" << endl;
	cout << "\t-> ";
	cin >> command;
	if(command == "1")	// 폴더 전체에서 검색
	{
		folderType folder;
		folder.setfoldernamefromKB();
		photoalbum.FindFolderAll(folder);

	}
	else if(command == "2")	// 현재 폴더에서만 검색
	{
		curFolder->FindFolder();
	}
	else
		cout << "\t잘못된 입력입니다." << endl;

	cout << endl << "\t";
	system("pause");
}

// 사진을 이름으로 검색함
void Application::FindNDisplayPhoto()
{
	cout << endl << endl;
	cout << "\t----- 사진 검색 -----" << endl;
	string command;

	cout << "\t1. 폴더 전체에서 검색" << endl;
	cout << "\t2. 현재 폴더에서만 검색" << endl;
	cout << "\t-> ";
	cin >> command;
	if(command == "1")	// 폴더 전체에서 검색
	{
		photoType photo;
		photo.setphotoNameKB();
		photoalbum.FindPhotoAll(photo);
	}
	else if(command == "2")	// 현재 폴더에서 검색
	{
		curFolder->FindPhoto();
	}
	else
		cout << "\t잘못된 입력입니다." << endl;

	cout << endl << "\t";
	system("pause");
}

// 파일을 가져오기위한 파일 디스크립터로 파일을 연다
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// 읽기위한 파일 열음
	
	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if(!m_InFile)	return 0;
	else	return 1;
}


// 파일을 쓰기위한 파일 디스크립터로 파일을 연다
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// 쓰기위한 파일 열음
	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if(!m_OutFile)	return 0;
	else	return 1;
}

// 읽기모드로 파일을 열고 파일의 모든 데이터를 읽으며 그 데이터를 리스트에 넣는다
int Application::ReadDataFromFile()
{

	// file open, open error가 발생하면 0을 리턴
	if(!OpenInFile("PhotoAlbum.txt"))
	{
		cout << "\t파일을 열 수 없습니다." << endl;
		return 0;
	}

	photoalbum.ReadFolder(m_InFile,bookmark);	// 폴더 읽어오기

	curFolder = &photoalbum;	// 현재 폴더 제일 상위폴더로

	m_InFile.close();	// 파일 닫기

	return 1;
}

// 쓰기모드로 파일을 열고 모든 데이터를 그 파일에 쓴다
int Application::WriteDataToFile()
{
	// file open, open error가 발생하면 0을 리턴
	if(!OpenOutFile("PhotoAlbum.txt"))
	{
		cout <<"\t실패했습니다." << endl;
		return 0;
	}


	photoalbum.WriteFolder(m_OutFile);	// 폴더 파일에 쓰기

	m_OutFile.close();	// 파일 닫기

	return 1;
}

// 폴더 이름 수정하기
void Application ::ModifyFoldrName()
{
	cout << endl << endl;
	cout << "\t----- 폴더 수정 -----" << endl;
	curFolder->ModifyFolderName();
	cout << endl;
	system("pause");
}

// 사진 정보 수정하기
void Application ::ModifyPhoto()
{
	cout << endl << endl;
	cout << "\t----- 사진 수정 -----" << endl;
	curFolder->ModifyPhoto();
	cout << endl;
	system("pause");
}

// 비밀번호 변경
void Application::changePassword()
{
	cout << endl << endl;
	cout << "\t----- 비밀번호 변경 -----" << endl;

	if(!OpenInFile(("login.txt")))
	{
		cout << "\t실행 오류! login.txt 확인바람." << endl;
		cout << endl << "\t";
		system("pause");
		return;
	}

	string password;	// 현재 비밀번호

	m_InFile >> password;

	m_InFile.close();

	string m_password;	// 사용자가 입력한 비밀번호
	string newpassword;	// 바꿀 비밀번호
	string repassword;	// 비밀번호 확인

	cout << "\t기존의 비밀번호 입력 : ";
	cin >> m_password;
	
	if( m_password == password )	// 현재 비밀번호와 사용자가 입력한 비밀번호가 같을시
	{
		if(!OpenOutFile(("login.txt")))
		{
			cout << "\t실행 오류! login.txt 확인바람." << endl;
			cout << endl << "\t";
			system("pause");
			return;
		}

		cout << endl << "\t새 비밀번호 입력 : ";
		cin >> newpassword;

		cout << endl << "\t한번 더 입력해주세요 : ";
		cin >> repassword;

		if( newpassword == repassword )	// 새 비밀번호와 다시 입력한 비밀번호가 같을 시
		{
			m_OutFile << newpassword;
			cout << "\t비밀번호 변경 완료!" << endl;
			m_OutFile.close();

			cout << endl << "\t";
			system("pause");
			return;
		}
		
		cout << endl << "\t비밀번호 변경 실패" << endl;	// 새 비밀번호와 다시 입력한 비밀번호가 다를 시
		m_OutFile << password;
		m_OutFile.close();
	}
	else	// 비밀번호가 틀렸을 시
	{
		cout << "\t비밀번호가 옳지 않습니다." << endl;
		m_OutFile.close();
	}

	cout << endl << "\t";
	system("pause");
}

// 로그인 한다.
bool Application ::login()
{
	if(!OpenInFile(("login.txt")))
	{
		cout << "\t실행 오류! login.txt 확인바람." << endl;
		return false;
	}

	string password;
	string m_password;
	m_InFile >> password;

	while(1)
	{
		cout << endl << endl << endl << endl;
		cout << "\t\t\tPhotoManagementSystem" << endl << endl << endl << endl;

		if( password == "1234" )	// 비밀번호가 1234일때 알려준다.
		{
			cout << "\t초기 비밀번호 - 1234" << endl << endl << endl;
		}

		cout << "\t\t Password : ";
		cin >> m_password;

		if( password != m_password )	// 로그인 실패시
		{
			system("cls");
			continue;
		}
		else	// 로그인 성공시
		{
			system("cls");
			m_InFile.close();
			ReadDataFromFile();	// 데이터를 불러옴
			return true;
		}
	}
}

// 즐겨찾기 추가
void Application::bookmarkAdd()
{
	cout << endl << endl;
	cout << "\t----- 즐겨찾기 추가 -----" << endl;
	curFolder->bookmarkAdd_F(bookmark);
	cout << endl << "\t";
	system("pause");
}

// 즐겨찾기 삭제
void Application::bookmarkDelete()
{
	cout << endl << endl;
	cout << "\t----- 가장 최근 날짜 즐겨찾기 삭제 -----" << endl;
	photoType* photo;
	if(bookmark.Get(photo) == NULL )
	{
		cout << "\t삭제에 실패했습니다." << endl;
	}
	else
	{
		photo->setbook(0);
		cout << "\t삭제에 성공했습니다." << endl;
		
	}

	cout << endl << "\t";
	system("pause");
}

// 즐겨찾기 목록 출력
void Application::bookmarkPrint()
{
	cout << endl << endl;
	cout << "\t----- 즐겨찾기 목록 출력 -----" << endl;
	bookmark.PrintHeap();

	cout << endl << "\t";
	system("pause");
}

// 사진 잘라내기
void Application::cutoff()
{
	cout << endl << endl;
	cout << "\t----- 사진 잘라내기 -----" << endl;
	if( Is_tempPhoto == true )
	{
		cout << "\t이미 잘라놓은 사진이 있습니다. 먼저 처리해주세요" << endl;
	}
	else if( curFolder->cutoff_F(tempPhoto) == true )
		Is_tempPhoto = true;

	cout << endl << "\t";
	system("pause");
}

// 사진 붙여넣기
void Application::paste()
{

	cout << endl << endl;
	if( Is_tempPhoto == false )
	{
		cout <<"\t잘라놓은 사진이 없습니다." << endl;
	}
	else
	{
		cout << "\t----- 사진 붙여넣기 -----" << endl;
		if( curFolder->paste_F(tempPhoto) == true )
			Is_tempPhoto = false;
	}

	cout << endl << "\t";
	system("pause");
}

// 사진 숨기기
void Application::hidePhoto()
{
	cout << endl << endl;
	cout << "\t----- 사진 숨기기 -----" << endl;
	curFolder->hidePhoto_F();

	cout << endl << "\t";
	system("pause");
}

// 사진 숨김 해제
void Application::un_hidePhoto()
{
	cout << endl << endl;
	cout << "\t----- 사진 숨김 해제 -----" << endl;
	curFolder->un_hidePhoto_F();
	cout << endl << "\t";
	system("pause");
}

// 현재 폴더의 숨긴 사진들 출력
void Application::print_hidePhoto()
{
	cout << endl << endl;
	cout << "\t----- 현재 폴더의 숨긴 사진 출력 -----" << endl;
	curFolder->print_hidePhoto_F();

	cout << endl << "\t";
	system("pause");
}