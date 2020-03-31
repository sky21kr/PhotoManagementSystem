#include"SortedList.h"

/**
*	사진타입 클래스
*/
class photoType
{
public:
	
	// 기본 생성자
	photoType()
	{
		photoName = "";
		date = "";
		size = 0;
	}
	/**
	*	@brief	사진의 정보를 출력함
	*	@pre	사진의 정보가 설정되어져 있어야함
	*	@post	없음
	*/
	void DisplayPhoto();

	/**
	*	@brief	사진의 이름을 받아옴
	*	@pre	사진의 이름이 설정되어져 있어야함
	*	@post	없음
	*	@param	사진의 이름
	*/
	string GetName();

	/**
	*	@brief	사진의 날짜를 받아옴
	*	@pre	사진의 날짜가 설정되어져 있어야함
	*	@post	없음
	*	@return	사진의 날짜를 리턴함
	*/
	string getdate();

	/**
	*	@brief	사진의 사이즈를 받아옴
	*	@pre	사진의 사이즈가 설정되어져 있어야함
	*	@post	없음
	*	@return	사진의 사이즈를 리턴함
	*/
	int getsize();

	/**
	*	@brief	숨김 상태를 반환함
	*	@pre	없음
	*	@post	없음
	*	@return 숨김상태면 true 아니면 false 반환
	*/
	bool gethide();

	/**
	*	@brief  즐겨찾기 상태를 반환함
	*	@pre	없음
	*	@post	없음
	*	@return	즐겨찾기상태면 true, 아니면 false 반환 
	*/
	int getbook();

	/**
	*	@brief	사진의 내용을 받아옴
	*	@pre	사진의 내용이 설정되어져 있어야함
	*	@post	없음
	*	@return	사진의 내용을 리턴함
	*/
	string getcontent();

	/**
	*	@brief	사진의 이름을 키보드로 부터 받아 설정함
	*	@pre	없음
	*	@post	사진의 이름이 설정됨
	*/
	void setphotoNameKB();

	/**
	*	@brief	사진의 생성날짜를 키보드로부터 받아 설정함
	*	@pre	없음
	*	@post	사진의 생성날짜가 설정됨
	*/
	void setdateKB();

	/**
	*	@brief	사진의 사이즈를 키보드로부터 받아 설정함
	*	@pre	없음
	*	@post	사진의 사이즈가 설정됨
	*/
	void setsizeKB();

	/**
	*	@brief	사진의 내용을 키보드로부터 받아 설정함
	*	@pre	없음
	*	@post	사진의 내용이 설정됨
	*/
	void setcontentKB();

	/**
	*	@brief	사진의 이름을 설정함
	*	@pre	없음
	*	@post	사진의 이름이 설정됨
	*	@param	temp_name	사진의 이름
	*/
	void setname(string temp_name);

	/**
	*	@brief	사진의 날짜를 설정함
	*	@pre	없음
	*	@post	사진의 날짜가 설정됨
	*	@param	temp_date	사진의 날짜
	*/
	void setdate(string temp_date);
	
	/**
	*	@brief	사진의 사이즈를 설정함
	*	@pre	없음
	*	@post	사진의 사이즈가 설정됨
	*	@param	temp_size	사진의 사이즈
	*/
	void setsize(int temp_size);

	/**
	*	@brief	사진의 내용을 설정함
	*	@pre	없음
	*	@post	사진의 내용이 설정됨
	*	@param	temp_content	사진의 내용
	*/
	void setconstent(string temp_content);

	/**
	*	@brief	숨김 상태를 설정함
	*	@pre	없음
	*	@post	숨김 상태가 설정됨
	*	@param	temp_hide 숨김 상태
	*/
	void sethide(bool temp_hide);

	/**
	*	@brief	즐겨찾기 상태를 설정함
	*	@pre	없음
	*	@post	즐겨찾기 상태가 설정됨
	*	@param	temp_book 즐겨찾기 상태
	*/
	void setbook(int temp_book);

	/**
	*	@brief	사진의 순서를 비교함
	*	@pre	사진리스트가 초기화 되어져 있어야함
	*	@post	없음
	*	@param	data	이름이 설정된 데이터
	*	@return 현재 사진의 이름순서가 빠르면 GREATER 같으면 EQUAL 느리면 LESS를 반환함
	*/
	RelationType CompareByName(const photoType &data);

	// 연산자 오버로딩 이름값을 비교
	bool operator>(photoType item);
	
	// 연산자 오버로딩 이름값을 비교
	bool operator<(photoType item);
private:
	string photoName;	///< 사진이름
	string date;		///< 사진생성날짜
	int size;			///< 사진크기
	string content;		///< 사진내용
	bool hide;			///< 숨김상태
	int book;			///< 즐겨찾기 상태
};