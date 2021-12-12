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
11. 
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
  ```C++
  
  ```
- Save : Content Edit Dialog의 내용을 HTML 문서로 저장
- Exit : 프로그램 종료


  
### 7. Main Menu - Edit
### 8. Main Menu - Information
### 9. 결론 및 느낀 점
### 10. 향후 계획
