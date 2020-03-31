#pragma once
#include"SortedList.h"
#include"BinarySearchTree.h"
#include<string>
#include<iostream>
#include"photoType.h"
#include "heap_recursive.h"
using namespace std;

#define FILENAMESIZE 1024
/**
*	폴더 타입 클래스
*/
class folderType
{
public:
	/**
	*	기본 생성자
	*/
	folderType()
	{
		foldername = "";
		date = "";
		numberOfItems = 0;
		numberOfhide = 0;
	}

	/**	
	*	소멸자
	*/
	~folderType()
	{
	}

	/**
	*	@brief	폴더를 추가함
	*	@pre	폴더 리스트가 있어야함
	*	@post	폴더 리스트에 데이터가 추가되고 numberOfItems가 1 증가함
	*/
	void addFolder();

	/**
	*	@brief	사진을 추가함
	*	@pre	사진 리스트가 있어야함
	*	@post	사진 리스트에 데이터가 추가되고 numberOfItems가 1 증가함
	*/
	void addPhoto();

	/**
	*	@brief	폴더를 삭제함
	*	@pre	폴더 리스트가 있어야함
	*	@post	폴더 리스트의 데이터가 삭제되고 numberOfItems가 1 감소함
	*/
	void deleteFolder();

	/**
	*	@brief	모든 하위 폴더를 삭제함
	*	@pre	폴더 리스트가 있어야함
	*	@post	폴더 리스트가 비워짐 
	*/
	void deleteAllFolder();

	/**
	*	@brief	사진을 삭제함
	*	@pre	사진 리스트가 있어야함
	*	@post	사진 리스트의 데이터가 삭제되고 numberOfItems가 1 감소함
	*/
	void deletePhoto();

	/**
	*	@brief	현재 폴더의 파일을 이름순으로 출력함
	*	@pre	현재 폴더의 폴더리스트 파일리스트가 있어야함
	*	@post	없음
	*/
	void displayFolderByName();

	/**
	*	@brief	폴더의 이름을 받아옴
	*	@pre	폴더의 이름이 설정되어져 있어야함
	*	@post	없음
	*	@return	폴더의 이름
	*/
	string GetName();

	/**
	*	@brief	폴더의 생성날짜를 받아옴
	*`	@pre	폴더의 생성날짜가 설정되어져 있어야함
	*	@post	없음
	*	@return	폴더의 생성날짜
	*/
	string getdate();

	/**
	*	@brief	폴더의 아이템 수를 받아옴
	*	@pre	폴더의 아이템 수가 설정되어져 있어야함
	*	@post	없음
	*	@return	폴더의 아이템 수
	*/
	int getnumberOfItems();
	
	/**
	*	@brief	폴더의 이름을 키보드로부터 입력받음
	*	@pre	없음
	*	@post	폴더의 이름이 설정됨
	*/
	void setfoldernamefromKB();

	/**
	*	@brief	폴더의 생성날짜를 키보드로부터 입력받음
	*	@pre	없음
	*	@post	폴더의 생성날짜가 설정됨
	*/
	void setdatefromKB();
	
	/**
	*	@brief	폴더의 이름을 설정함
	*	@pre	없음
	*	@post	폴더의 이름이 설정됨
	*	@param	name	정할 폴더 이름
	*/
	void setfoldername(string name);

	/**
	*	@brief	폴더의 날짜를 설정함
	*	@pre	없음
	*	@post	폴더의 날짜가 설정됨
	*	@param	temp_date	설정할 폴더 날짜
	*/
	void setdate(string temp_date);

	/**
	*	@brief	폴더의 아이템 수를 설정함
	*	@pre	없음
	*	@post	폴더의 아이템 수가 설정됨
	*	@param	정할 폴더의 아이템 수
	*/
	void setnumberOfItems(int number);

	/**
	*	@brief	이름을 비교함
	*	@pre	이름이 설정된 folderType형 데이터가 필요함, 폴더 리스트가 초기화 되어져있어야함
	*	@post	없음
	*	@param	data	이름이 설정된 데이터
	*	@return	현재 폴더의 이름 순서가 빠르면 GREATER 같으면 EQUAL 느리면 LESS를 반환함
	*/
	RelationType CompareByName(const folderType &data);

	/**
	*	@brief	현재 폴더를 이동함
	*	@pre	curFolder가 초기화 되어져 있어야함
	*	@post	없음
	*	@return 옮길 폴더의 주소값
	*/
	folderType* moveFolder();

	/**
	*	@brief	현재 폴더의 폴더를 이름으로 찾아서 정보를 출력함 키워드가 포함되면 출력
	*	@pre	없음
	*	@post	없음
	*/
	void FindFolder();

	/**
	*	@brief	폴더 전체에서 폴더를 검색하기 위한 함수 키워드가 포함되면 출력
	*	@pre	없음
	*	@post	없음
	*	@param	namefolder 이름만 가진 폴더
	*/
	void FindFolderAll(folderType namefolder);
	
	/**
	*	@brief	폴더 전체에서 사진을 검색하기 위한 함수 키워드가 포함되면 출력
	*	@pre	없음
	*	@post	없음
	*	@param	namephoto 이름만 가진 사진
	*/
	void FindPhotoAll(photoType namephoto);

	/**
	*	@brief	현재 폴더의 사진을 이름으로 찾아서 정보를 출력함 키워드가 포함되면 출력
	*	@pre	없음
	*	@post	없음
	*/
	void FindPhoto();

	/**
	*	@brief	폴더의 정보를 출력함
	*	@pre	폴더의 정보가 초기화 되어져 있어야함
	*	@post	없음
	*/
	void DisplayFolderRecordOnScreen();

	/**
	*	@brief	데이터를 파일에 씀
	*	@pre	쓸 파일이 만들어져 있어야함
	*	@post	파일에 데이터가 써짐
	*	@param	WF	쓰기 위해 만듬
	*/
	void WriteFolder(ofstream& WF);

	/**
	*	@brief	데이터를 파일로부터 읽어옴
	*	@pre	불러올 파일이 만들어져 있어야함
	*	@post	파일로부터 데이터를 불러옴
	*	@param	RF	읽어오기 위해 만듬
	*/
	void ReadFolder(ifstream& RF,MaxHeap<photoType*> &bookmark);

	/**
	*	@brief	폴더의 이름을 수정함
	*	@pre	찾을 폴더가 만들어져 있어야함
	*	@post	폴더의 이름이 수정됨
	*/
	void ModifyFolderName();

	/**
	*	@brief	사진의 정보를 수정함
	*	@pre	찾을 사진이 만들어져 있어야함
	*	@post	사진의 정보가 수정됨
	*/
	void ModifyPhoto();

	/**
	*	@brief	즐겨찾기를 추가함
	*	@pre	없음
	*	@post	즐겨찾기가 추가됨
	*	@param	WF	쓰기 위해 만듬	bookmark 즐겨찾기 목록에 추가하기 위해
	*/
	void bookmarkAdd_F(MaxHeap<photoType*> &bookmark);

	/**
	*	@brief	사진 잘라내기
	*	@pre	이미 잘라둔 사진이 없어야함
	*	@post	잘라낸 사진이 임시 저장됨
	*	@param	tempPhoto 사진을 잘라내기 위해 만듬
	*	@return 성공하면 true, 실패하면 false
	*/
	bool cutoff_F(photoType &tempPhoto);
	
	/**
	*	@brief	사진 붙여넣기
	*	@pre	잘라둔 사진이 있어야함
	*	@post	사진이 붙여넣어짐
	*	@param	tempPhoto 사진을 붙여넣기 위해 만듬
	*	@return 성공하면 true, 실패하면 false
	*/
	bool paste_F(photoType tempPhoto);

	/**
	*	@brief	사진 숨기기
	*	@pre	사진이 숨김상태가 아니여야함
	*	@post	사진이 숨김 상태가 됨
	*/
	void hidePhoto_F();

	/**
	*	@brief	사진 숨김 해제
	*	@pre	사진이 숨김 상태여야함
	*	@post	사진의 숨김 상태가 해제됨
	*/
	void un_hidePhoto_F();
	
	/**
	*	@brief	숨긴 사진 출력
	*	@pre	없음
	*	@post	없음
	*/
	void print_hidePhoto_F();
	
	/**
	*	@brief	숨긴 사진 수를 설정함
	*	@pre	없음
	*	@post	숨긴 사진의 수가 설정됨
	*	@param	m_setnumberOfhide 숨긴 사진 수
	*/
	void setnumberOfhide(int m_setnumberOfhide);

	/**
	*	@brief	숨긴 사진의 수를 받아옴
	*	@pre	numberOfhide이 설정되어져 있어야함
	*	@post	없음
	*	@return	숨긴 사진의 수
	*/
	int getnumberOfhide();
private:

	string foldername;	///< 폴더이름
	string date;		///< 폴더생성날짜
	int numberOfItems;	///< 폴더에 포함된 아이템 수
	int numberOfhide;	///< 숨긴 사진 수
	SortedList<folderType> folderList;	///< 폴더리스트
	BinarySearchTree<photoType> photoList;	///< 포토리스트
};