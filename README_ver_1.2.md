# README_ver_1.2
- MFC와 HTML 언어를 사용하여 HTML에 대해 모르더라도 간단한 웹 페이지를 만들 수 있는 프로그램

### Stacks & Skills
<img alt="C++" src ="https://img.shields.io/badge/C++-00599C.svg?&style=for-the-badge&logo=c%2B%2B&logoColor=white"/>    <img alt="MFC" src ="https://img.shields.io/badge/MFC-5C2D91.svg?&style=for-the-badge&logo=Visual Studio&logoColor=white"/>    <img alt="HTML5" src ="https://img.shields.io/badge/HTML5-E34F26.svg?&style=for-the-badge&logo=HTML5&logoColor=white"/>

### 목차
---
1. 개발 배경
2. 본인의 역할
3. 기획 일정
4. 웹 페이지의 구성 요소
5. 메뉴 구성
6. Main Menu - File
7. Main Menu - Edit
8. Main Menu - Information
9. 결론 및 느낀 점
10. 향후 계획
---

### 1. 개발 배경
* 대학교 때, 웹 페이지를 개발했던 적이 잇따. 이때 HTML과 CSS에 대해 전혀 모르는 상태였기 때문에 개발하는 데 힘들었던 적이 있었다. 파워포인트 프로그램처럼, HTML과 CSS를 몰라도 웹페이지를 만들 수 있는 프로그램이 있었으면 좋겠다는 생각을 하게 되었다.
* ![image](https://user-images.githubusercontent.com/49339278/145723060-6591b86e-91e7-455e-be80-57f36995e4c8.png)


### 2. 본인의 역할
- 팀 구성 : 개인
- 역할
  - 프로젝트 기획
  - 프로젝트 기획에 따른 서비스 구현
  - 프로젝트 기획에 따른 서비스 검토
  
### 3. 기획 일정
| |2021.09.06|2021.09.07|2021.09.08|2021.09.09|2021.09.10|
|:--:|:--:|:--:|:--:|:--:|:--:|
|서비스 기획|■| | | | |
|서비스 구현| |■|■|■| |
|서비스 검토| | | | |■|

### 4. 웹 페이지의 구성 요소
![image](https://user-images.githubusercontent.com/49339278/145723082-15da0197-9239-4da4-8b04-c6c4c8793074.png)

### 5. 메뉴 구성
- File : Open / Save / Exit
- Edit : 머리말 / 내용 / 하이퍼링크 / 이미지
- Information : Web Maker 정보 / 도움말

![image](https://user-images.githubusercontent.com/49339278/145723144-6fdfed07-acd9-41e0-a6dc-84f1e638af14.png)
- 기능 요약
  - Page 구역에 있는 3개의 Edit Dialog을 합친 후, [만들기] 버튼을 클릭하여 HTML 파일을 저장한다.
  - 페이지 제목을 입력한 후, EUC-KR 버튼을 클릭하면 Primary Edit Dialog에 ```<!DOCTYPE html>```, ```<html lang = "ko">```가 입력된다.
  - 그리고 2번 Edit Dialog에 인코딩 정보(EUC-KR)와 페이지 제목이 입력된다.
  - Content Edit Dialog에 값을 입력한 후, Edit 메뉴에 있는 머리말, 내용, 이미지 기능을 사용해 ```<body>``` Edit Dialog에 값을 입력할 수 있다.
  - 하이퍼링크 내용과 주소를 각각 입력하여 Edit 메뉴에 있는 하이퍼링크 기능을 이용해 ```<body>``` Edit Dialog에 값을 입력할 수 있다.
  
- 상세 설명
  
  |번호|설명|
  |:---:|:--|
  |1|```<!DOCTYPE html>```과 ```<html>```이 담긴 Primary Edit Dialog, 수정이 불가능하다.|
  |2|웹 페이지의 인코딩 방식과 페이지 제목을 입력 받는 Edit Dialog. 수정이 불가능하다.|
  |3|웹 페이지의 내용을 입력 받는 Edit Dialog. 수정이 불가능하다.|
  |4|웹 페이지의 내용을 입력할 수 있는 Edit Dialog.|
  |5|하이퍼링크의 내용과 주소를 입력 받는 Edit Dialog.|
  |6|페이지 제목을 입력 받는 Edit Dialog|
  |7|페이지 제목과 EUC-KR 인코딩 방식을 '2'번 Edit Dialog에 입력하는 Radio Button|
  |8|1과 2, 3의 Edit Dialog을 합쳐서 html 문서로 저장하는 버튼|
  |9|프로그램의 종료 기능이 담긴 버튼|
  
![image](https://user-images.githubusercontent.com/49339278/145723347-42c71b6b-3eb4-43bc-8823-709a1d093fbe.png)

### 6. Main Menu - File
- Open : txt File Open 및 Migration
  ![image](https://user-images.githubusercontent.com/49339278/145723398-c3d2d059-9c39-4a68-bbd5-64fe0272794a.png)
- Save : Content Edit Dialog의 내용을 HTML 문서로 저장
  ![image](https://user-images.githubusercontent.com/49339278/147534818-687e7e51-fcc4-4ce8-bcdd-119192131261.png)
- Exit : 프로그램 종료

### 7. Main Menu - Edit
- 머리말 : ```<h1>```(가장 큰 글씨) ~ ```<h6>```(가장 작은 글씨) 태그
![image](https://user-images.githubusercontent.com/49339278/147535014-e941de0f-3f2c-4f5e-8cf9-9ca95f6ff9d7.png)
![image](https://user-images.githubusercontent.com/49339278/147535023-13fb3a1b-f991-4e45-acbd-39351ee43c5d.png)


- 내용 : 내용 입력 기능 (```<p>``` 태그)
![image](https://user-images.githubusercontent.com/49339278/147535055-8df7d09b-9135-4982-8f7f-32d8140a6a30.png)
![image](https://user-images.githubusercontent.com/49339278/147535061-77a5f4a7-9dc2-4006-ac89-6909bcfd6737.png)


- 하이퍼링크 : 하이퍼링크 생성 및 입력 기능 ```<a href "주소 URL"> 내용 </a>```
![image](https://user-images.githubusercontent.com/49339278/147535072-c4d30abf-933c-4793-a936-c7fe4ddd839a.png)
![image](https://user-images.githubusercontent.com/49339278/147535078-494601db-14ed-44e4-92b6-c5062326356a.png)


- 이미지 : 웹 이미지 첨부하기 / 이미지 (비활성화) ```<img src = "주소">```
![image](https://user-images.githubusercontent.com/49339278/147535122-b2327dfa-9370-428a-96ec-347dc513dae7.png)
![image](https://user-images.githubusercontent.com/49339278/147535128-3858140f-e88f-40b6-988a-1b5f08be278f.png)
![image](https://user-images.githubusercontent.com/49339278/147535132-a1fd5038-31cc-4d10-96e0-2f958da07899.png)

### 8. Main Menu - Information
- Web Maker 정보 : 프로그램 제작 버전, 제작자 등의 프로그램 정보가 담긴 Dialog 실행
![image](https://user-images.githubusercontent.com/49339278/147535310-cdfe38cb-cc29-4fac-baea-d5011a6c08dd.png)

- 도움말 : 프로그램 사용 방법이 작성된 Dialog 실행 (Ver 1.1 버전 이후 생략)

### 9. [만들기] button
![image](https://user-images.githubusercontent.com/49339278/147535430-c1005196-4b7d-4555-bd44-34558fe3db65.png)
![image](https://user-images.githubusercontent.com/49339278/147535435-c2536b4f-d186-49c6-b552-91df395b0628.png)
![image](https://user-images.githubusercontent.com/49339278/147535442-03f6fdd9-e0b3-45dc-a631-0981c1828be0.png)
```C++

```

### 10. 결론 및 느낀 점
- 초기 기획으로는 HTML과 CSS 기능을 구현하는 것이었으나, 5일이라는 짧은 개발 기간이 주어졌기 때문에 HTML 기능 일부분만을 구현할 수 있었다. 
- 첫 프로그램 기획 및 개발 경험으로, 처음에 기획할 때 가능한지 아닌지 의문이 들었는데, 5일이라는 개발 기간 동안에 열심히 노력하다 보니, 원하는 프로그램을 개발할 수 있게 되었다.

- 이 프로그램을 기획하게 된 배경으로, 대학교 때 웹 페이지를 개발했던 적이 있다. 이때 HTML과 CSS에 대해 전혀 모르는 상태였기 때문에 개발하는 데 힘들었던 적이 있었다. 그때 파워포인트 프로그램 처럼, HTML과 CSS 언어 없이도 웹페이지를 만들 수 있는 프로그램이 있으면 좋겠다는 생각을 하게 되었고, 우연히 기회가 생겨서 Web Page Editor 프로그램을 개발하게 되었다.

- 이 경험을 통해서 개발자와 나의 성향이 일치한다는 사실을 알게 되었고, 불편한 점을 프로그램을 개발함으로써 해결하는 프로그램 개발자가 되겠다는 다짐하게 되었다.

### 11. 향후 계획
- 현재 MFC 프레임워크는 마이크로소프트에서 지원되지 않는 프레임워크라는 사실을 알게 되었다. 그리고 MFC를 사용하는 업체들은 있지만, 새로 개발하는 프로그램에 적용하는 것보다 유지보수하는 데 사용한다는 사실을 알게 되었다.
- MFC와 달리 WinForm과 WPF, QT, 플러터 등 윈도우 애플리케이션을 개발할 수 있는 라이브러리는 매우 많았다. 여러 프레임워크의 특징을 살펴본 결과, Windows Form 라이브러리를 사용하여 프로그램을 개발하는 것이 효율적이라고 판단하였다.
- 추가로 C++ 언어로 Windows Form 프레임워크를 이용할 수 있다는 확인하였다. 그런 점을 고려하였을 때, Ver 2.0 프로그램을 개발할 때 C++ 언어로 Windows Form 프레임워크를 사용하는 것으로 결정하였습니다.
