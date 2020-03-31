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
*	���� Ÿ�� Ŭ����
*/
class folderType
{
public:
	/**
	*	�⺻ ������
	*/
	folderType()
	{
		foldername = "";
		date = "";
		numberOfItems = 0;
		numberOfhide = 0;
	}

	/**	
	*	�Ҹ���
	*/
	~folderType()
	{
	}

	/**
	*	@brief	������ �߰���
	*	@pre	���� ����Ʈ�� �־����
	*	@post	���� ����Ʈ�� �����Ͱ� �߰��ǰ� numberOfItems�� 1 ������
	*/
	void addFolder();

	/**
	*	@brief	������ �߰���
	*	@pre	���� ����Ʈ�� �־����
	*	@post	���� ����Ʈ�� �����Ͱ� �߰��ǰ� numberOfItems�� 1 ������
	*/
	void addPhoto();

	/**
	*	@brief	������ ������
	*	@pre	���� ����Ʈ�� �־����
	*	@post	���� ����Ʈ�� �����Ͱ� �����ǰ� numberOfItems�� 1 ������
	*/
	void deleteFolder();

	/**
	*	@brief	��� ���� ������ ������
	*	@pre	���� ����Ʈ�� �־����
	*	@post	���� ����Ʈ�� ����� 
	*/
	void deleteAllFolder();

	/**
	*	@brief	������ ������
	*	@pre	���� ����Ʈ�� �־����
	*	@post	���� ����Ʈ�� �����Ͱ� �����ǰ� numberOfItems�� 1 ������
	*/
	void deletePhoto();

	/**
	*	@brief	���� ������ ������ �̸������� �����
	*	@pre	���� ������ ��������Ʈ ���ϸ���Ʈ�� �־����
	*	@post	����
	*/
	void displayFolderByName();

	/**
	*	@brief	������ �̸��� �޾ƿ�
	*	@pre	������ �̸��� �����Ǿ��� �־����
	*	@post	����
	*	@return	������ �̸�
	*/
	string GetName();

	/**
	*	@brief	������ ������¥�� �޾ƿ�
	*`	@pre	������ ������¥�� �����Ǿ��� �־����
	*	@post	����
	*	@return	������ ������¥
	*/
	string getdate();

	/**
	*	@brief	������ ������ ���� �޾ƿ�
	*	@pre	������ ������ ���� �����Ǿ��� �־����
	*	@post	����
	*	@return	������ ������ ��
	*/
	int getnumberOfItems();
	
	/**
	*	@brief	������ �̸��� Ű����κ��� �Է¹���
	*	@pre	����
	*	@post	������ �̸��� ������
	*/
	void setfoldernamefromKB();

	/**
	*	@brief	������ ������¥�� Ű����κ��� �Է¹���
	*	@pre	����
	*	@post	������ ������¥�� ������
	*/
	void setdatefromKB();
	
	/**
	*	@brief	������ �̸��� ������
	*	@pre	����
	*	@post	������ �̸��� ������
	*	@param	name	���� ���� �̸�
	*/
	void setfoldername(string name);

	/**
	*	@brief	������ ��¥�� ������
	*	@pre	����
	*	@post	������ ��¥�� ������
	*	@param	temp_date	������ ���� ��¥
	*/
	void setdate(string temp_date);

	/**
	*	@brief	������ ������ ���� ������
	*	@pre	����
	*	@post	������ ������ ���� ������
	*	@param	���� ������ ������ ��
	*/
	void setnumberOfItems(int number);

	/**
	*	@brief	�̸��� ����
	*	@pre	�̸��� ������ folderType�� �����Ͱ� �ʿ���, ���� ����Ʈ�� �ʱ�ȭ �Ǿ����־����
	*	@post	����
	*	@param	data	�̸��� ������ ������
	*	@return	���� ������ �̸� ������ ������ GREATER ������ EQUAL ������ LESS�� ��ȯ��
	*/
	RelationType CompareByName(const folderType &data);

	/**
	*	@brief	���� ������ �̵���
	*	@pre	curFolder�� �ʱ�ȭ �Ǿ��� �־����
	*	@post	����
	*	@return �ű� ������ �ּҰ�
	*/
	folderType* moveFolder();

	/**
	*	@brief	���� ������ ������ �̸����� ã�Ƽ� ������ ����� Ű���尡 ���ԵǸ� ���
	*	@pre	����
	*	@post	����
	*/
	void FindFolder();

	/**
	*	@brief	���� ��ü���� ������ �˻��ϱ� ���� �Լ� Ű���尡 ���ԵǸ� ���
	*	@pre	����
	*	@post	����
	*	@param	namefolder �̸��� ���� ����
	*/
	void FindFolderAll(folderType namefolder);
	
	/**
	*	@brief	���� ��ü���� ������ �˻��ϱ� ���� �Լ� Ű���尡 ���ԵǸ� ���
	*	@pre	����
	*	@post	����
	*	@param	namephoto �̸��� ���� ����
	*/
	void FindPhotoAll(photoType namephoto);

	/**
	*	@brief	���� ������ ������ �̸����� ã�Ƽ� ������ ����� Ű���尡 ���ԵǸ� ���
	*	@pre	����
	*	@post	����
	*/
	void FindPhoto();

	/**
	*	@brief	������ ������ �����
	*	@pre	������ ������ �ʱ�ȭ �Ǿ��� �־����
	*	@post	����
	*/
	void DisplayFolderRecordOnScreen();

	/**
	*	@brief	�����͸� ���Ͽ� ��
	*	@pre	�� ������ ������� �־����
	*	@post	���Ͽ� �����Ͱ� ����
	*	@param	WF	���� ���� ����
	*/
	void WriteFolder(ofstream& WF);

	/**
	*	@brief	�����͸� ���Ϸκ��� �о��
	*	@pre	�ҷ��� ������ ������� �־����
	*	@post	���Ϸκ��� �����͸� �ҷ���
	*	@param	RF	�о���� ���� ����
	*/
	void ReadFolder(ifstream& RF,MaxHeap<photoType*> &bookmark);

	/**
	*	@brief	������ �̸��� ������
	*	@pre	ã�� ������ ������� �־����
	*	@post	������ �̸��� ������
	*/
	void ModifyFolderName();

	/**
	*	@brief	������ ������ ������
	*	@pre	ã�� ������ ������� �־����
	*	@post	������ ������ ������
	*/
	void ModifyPhoto();

	/**
	*	@brief	���ã�⸦ �߰���
	*	@pre	����
	*	@post	���ã�Ⱑ �߰���
	*	@param	WF	���� ���� ����	bookmark ���ã�� ��Ͽ� �߰��ϱ� ����
	*/
	void bookmarkAdd_F(MaxHeap<photoType*> &bookmark);

	/**
	*	@brief	���� �߶󳻱�
	*	@pre	�̹� �߶�� ������ �������
	*	@post	�߶� ������ �ӽ� �����
	*	@param	tempPhoto ������ �߶󳻱� ���� ����
	*	@return �����ϸ� true, �����ϸ� false
	*/
	bool cutoff_F(photoType &tempPhoto);
	
	/**
	*	@brief	���� �ٿ��ֱ�
	*	@pre	�߶�� ������ �־����
	*	@post	������ �ٿ��־���
	*	@param	tempPhoto ������ �ٿ��ֱ� ���� ����
	*	@return �����ϸ� true, �����ϸ� false
	*/
	bool paste_F(photoType tempPhoto);

	/**
	*	@brief	���� �����
	*	@pre	������ ������°� �ƴϿ�����
	*	@post	������ ���� ���°� ��
	*/
	void hidePhoto_F();

	/**
	*	@brief	���� ���� ����
	*	@pre	������ ���� ���¿�����
	*	@post	������ ���� ���°� ������
	*/
	void un_hidePhoto_F();
	
	/**
	*	@brief	���� ���� ���
	*	@pre	����
	*	@post	����
	*/
	void print_hidePhoto_F();
	
	/**
	*	@brief	���� ���� ���� ������
	*	@pre	����
	*	@post	���� ������ ���� ������
	*	@param	m_setnumberOfhide ���� ���� ��
	*/
	void setnumberOfhide(int m_setnumberOfhide);

	/**
	*	@brief	���� ������ ���� �޾ƿ�
	*	@pre	numberOfhide�� �����Ǿ��� �־����
	*	@post	����
	*	@return	���� ������ ��
	*/
	int getnumberOfhide();
private:

	string foldername;	///< �����̸�
	string date;		///< ����������¥
	int numberOfItems;	///< ������ ���Ե� ������ ��
	int numberOfhide;	///< ���� ���� ��
	SortedList<folderType> folderList;	///< ��������Ʈ
	BinarySearchTree<photoType> photoList;	///< ���丮��Ʈ
};