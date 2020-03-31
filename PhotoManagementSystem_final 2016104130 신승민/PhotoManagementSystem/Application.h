#pragma once
#include "SortedList.h"
#include "folderType.h"
#include "Stack.h"
#include "heap_recursive.h"

/**
*	폴더 관리를 위한 Applicaiton class
*/
class Application
{
public:
	/**
	*	기본 생성자
	*/
	Application()
	{
		curFolder = &photoalbum;					// 현재 폴더 주소를 설정
		curFolder->setfoldername("PhotoAlbum");	// 시작 폴더 이름 설정
		curFolder->setnumberOfItems(0);		// 시작 폴더의 아이템 개수 설정
		Is_tempPhoto = false;	// 사진 버퍼 빔
	}

	/**
	*	소멸자
	*/
	~Application()
	{
	}

	/**
	*	@brief	프로그램 작동
	*	@pre	프로그램 시작 전
	*	@post	프로그램이 종료됨
	*/
	void Run();

	/**
	*	@brief	커맨드 보여주고 사용자로부터 키 입력받기
	*	@pre	없음
	*	@post	없음
	*	@return 입력한 키
	*/
	int GetCommand();

	/**
	*	@brief	현재 폴더에 폴더를 더함
	*	@pre	curFolder가 초기화 되어져 있어야함
	*	@post	curFolder의 addFolder()를 불러옴
	*/
	void addFolderInterface();

	/**
	*	@brief	현재 폴더에 사진을 더함
	*	@pre	curFolder가 초기화 되어져 있어야함
	*	@post	curFolder의 addPhoto()를 불러옴
	*/
	void addPhotoInterface();

	/**
	*	@brief	현재 폴더의 폴더를 삭제함
	*	@pre	curFolder가 초기화 되어져 있어야함
	*	@post	curFolder의 deleteFolder()를 불러옴
	*/
	void deleteFolderInterface();

	/**
	*	@brief	현재 폴더의 사진을 삭제함
	*	@pre	curFolder가 초기화 되어져 있어야함
	*	@post	curFolder의 deletePhoto()를 불러옴
	*/
	void deletePhotoInterface();

	/**
	*	@brief	현재 폴더의 파일 개수들과 폴더들과 사진을 이름순으로 보여줌
	*	@pre	curFolder가 초기화 되어져 있어야함
	*	@post	없음
	*/
	void displayCurFolderByName();	
	
	/**
	*	@brief	현재 폴더를 이동함
	*	@pre	curFolder가 초기화 되어져 있어야함
	*	@post	curFolder의 주소값이 바뀌고 폴더 단계가 한단계 증가함
	*/
	void moveCurFolder();

	/**
	*	@brief	이전 폴더로 돌아감
	*	@pre	curFolder가 초기화 되어져 있어야함
	*	@post	curFolder의 주소값이 바뀌고 폴더 단계가 한단계 감소함
	*/
	void backFolder();

	/**
	*	@brief	폴더의 폴더를 이름으로 검색함 키워드가 포함되면 출력
	*	@pre	현재 폴더가 초기화 되어져 있어야함
	*	@post	없음
	*/
	void FindNDisplayFolder();

	/**
	*	@brief	폴더의 사진을 이름으로 검색함 키워드가 포함되면 출력
	*	@pre	현재 폴더가 초기화 되어져 있어야함
	*	@post	없음
	*/
	void FindNDisplayPhoto();

		/**
	*	@brief	파일에 쓰기위한 파일 디스크립터로 파일을 연다
	*	@pre	읽기 위한 파일이 존재해야합니다
	*	@post	읽기 위한 파일이 열린다
	*	@param	fileName	읽기 위한 파일의 이름
	*	@return	제대로 작동하면 1, 그렇지 않으면 0 리턴
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	읽어 오기위한 파일 디스크립터로 파일을 연다
	*	@pre	리스트가 초기화 되어져 있어야함
	*	@post	쓰기 위한 파일을 연다
	*	@param	fileName	쓰기 위한 파일을 열 파일 이름
	*	@return	제대로 작동하면 1, 그렇지 않으면 0을 리턴
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	읽기 모드로 파일을 열고 파일의 모든 데이터를 읽고 그 데이터를 리스트에 넣는다
	*	@pre	그 파일이 열려있지 않다.
	*	@post	파일로 그 리스트의 모든 데이터를 받아온다
	*	@return	제대로 작동하면 1, 그렇지 않으면 0을 리턴
	*/
	int ReadDataFromFile();

	/**
	*	@brief	파일을 읽기 모드로 열고 모든 데이터를 그 파일에 쓴다
	*	@pre	그 파일이 열려있지 않다
	*	@post	저장 파일에 리스트가 저장된다.
	*	@return	제대로 작동하면 1, 그렇지 않으면 0을 리턴
	*/
	int WriteDataToFile();

	/**
	*	@brief	폴더의 이름을 수정한다.
	*	@pre	폴더가 만들어져 있어야함
	*	@post	폴더의 이름이 바뀐다.
	*/
	void ModifyFoldrName();
	
	/**
	*	@brief	사진의 정보를 수정한다.
	*	@pre	사진이 만들어져 있어야함.
	*	@post	사진의 정보가 바뀐다.
	*/
	void ModifyPhoto();

	/**
	*	@brief	비밀번호를 변경한다
	*	@pre	login.txt파일이 만들어져 있어야한다.
	*	@post	login.txt의 비밀번호가 바뀐다.
	*/
	void changePassword();

	/**
	*	@brief	프로그램에 로그인 한다.
	*	@pre	login.txt파일이 만들어져있어야한다.
	*	@post	로그인 성공시 데이터가 불러와진다.
	*	@return	로그인 성공시 true, 실패시 false 리턴
	*/
	bool login();

	/**
	*	@brief	즐겨찾기 추가
	*	@pre	없음
	*	@post	bookmark가 추가됨
	*/
	void bookmarkAdd();

	/**
	*	@brief	즐겨찾기 삭제
	*	@pre	없음
	*	@post	bookmark가 하나 삭제됨
	*/
	void bookmarkDelete();

	/**
	*	@brief	즐겨찾기 출력
	*	@pre	즐겨찾기 목록이 있어야함
	*	@post	없음
	*/
	void bookmarkPrint();

	/**
	*	@brief	사진 잘라내기
	*	@pre	tempPhoto가 비워져 있어야함
	*	@post	tempPhoto에 사진이 들어감
	*/
	void cutoff();

	/**
	*	@brief	사진을 붙여넣음
	*	@pre	Is_tempPhoto가 true여야함 = 사진을 잘라낸 상태여야함
	*	@post	Is_tempPhoto가 false가 됨
	*/
	void paste();

	/**
	*	@brief	사진을 숨김
	*	@pre	사진이 숨김상태가 아니여야함
	*	@post	사진이 숨김상태가 됨
	*/
	void hidePhoto();

	/**
	*	@brief	사진의 숨김상태를 해제함
	*	@pre	사진이 숨김상태여야함
	*	@post	사진의 숨김상태가 풀림
	*/
	void un_hidePhoto();

	/**
	*	@brief	현재 폴더의 숨김 상태인 사진을 출력함
	*	@pre	없음
	*	@post	없음
	*/
	void print_hidePhoto();


private:
	ifstream m_InFile;		///< 파일을 읽기위한 준비
	ofstream m_OutFile;		///< 파일을 쓰기위한 준비

	int m_Command;			///< 사용자 입력
	folderType photoalbum;		///< 제일 처음 폴더
	folderType *curFolder;	///< 현재 폴더값의 주소를 가짐
	MaxHeap<photoType*> bookmark;	// 즐겨찾기

	Stack<folderType*> folderStack;	// 폴더 스택구조
	
	photoType tempPhoto;	// 사진 버퍼
	bool Is_tempPhoto;		// 사진 버퍼 찼나 안찼나
};