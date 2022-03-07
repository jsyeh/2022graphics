# 2022graphics

# Week01
第01週的上課內容

## Week01-1 OpenGL專案
1. CodeBlocks, File-New-Project, 選 OpenGL專案
2. 要記得...對應的目錄
3. 取個專案名
4. Build & Run, 可以看到彩色三角形在轉動

## Week01-2 WebGL 試試看

## Week01-3 GLUT專案
1. moodle下載 freeglut
2. 解壓縮到 桌面 freeglut
3. 改檔名 lib\libglut32.a
4. File-New-Project, GLUT專案
5. 專案名
6. GLUT在桌面的freeglut

## Week01-4 利用 Git 指令, 備份今天上課的內容
```
Week01-4 建 GitHub 倉庫
1. 登入 GitHub
2. 建 2022graphics 的 repo倉庫
2.1. 要設定 Public
2.2. 要 README.md
2.3. Add .gitignore 設定 C++

3. 利用 Git指令下載
3.0. 安裝 Git for Windows
3.1. 開啟 Git Bash
3.2. cd desktop 進入桌面
3.2. git clone https://你的倉庫網址
3.3. 查看 桌面,多了 2022graphics 目錄

3.4. 把今天的程式 複製到 剛剛目錄

4. 把修改的資料, 推送到雲端
4.1. cd 2022graphics 進入你的倉庫
4.2. git status 看你的狀況(紅的,多了目錄)
4.3. git add . 把檔案加進帳冊
4.4. git status 再看一次(綠的)

這裡要加入
git config --global user.email "你的email"
git config --global user.name "你的名"
git commit -m "上傳第1週"

4.5. git push 推送到雲端, BUT要登入
4.6. 在 Chrome記得再登入哦
```


# Week03

1. 先把第01週的程式從 GitHub 下載
2. 跑今天的範例 Shape.exe
3. 今天的主題: 點、線、面、色彩
4. 複習上週的課堂作業 GLUT 要裝 freeglut
4.1. 把 freeglut.....zip 的freeglut拉到桌面
4.2. 再把 桌面\freeglut\lib\libglut32.a 複製好
4.3. 就可以跑上週的 week01_GLUT 範例了!!!

5. 今天的主角要出現了(把上週的2個程式會合併)
5.1. File-New-Project, GLUT專案, week03_color
小心, ...的目錄要在桌面
(freeglut目錄不要錯) (目前看起來和上週 week01_GLUT一樣)
5.2. 把程式全刪掉!!!!!!

回家作業: 小畫家,可幫忙 (1) 小滴管+編輯色彩, 得到色彩的值(0-255) => 0.0~1.0
(2) 座標,可得到座標 0...300 => -1...+1

## 下載 Win32 的Example範例
- https://jsyeh.org/3dcg10/
- windows.zip => 下載\windows\Shape.exe 執行它

3. 今天的主題:
glBegin( GL_畫法 )開始畫

glEnd()結束畫

step01-0_簡介今天的上課內容,同時把GitHub 的式利用 Git指令下載下來,待命使用。

step01-1_今天上課的範例,是要介紹「點、線、面、色彩」,所以從 jsyeh.org 的 3dccg10 裡下載今天的Windows範例, 今天要跑的是 Shape.exe

step01-2_在範例Shape.exe裡,除了左邊按mouse右鍵可以切換Big及Color外,右邊也可以用mouse去drag拖曳裡面的數值。

step01-3_介紹等一下要做的「彩色三角形」,會使用glBegin() glEnd() 並在裡面插入 glColor3f() 及 glVertex3f() 配合上週做的 GLUT專案,便可完成。

step02-1_為了跑上週的week01_GLUT範例,我們需要把 freeglut 裝好(Moodle裡有一份,桌面裡也有一份), 請把 freeglut 複製到桌面, 把 lib 的 libglut32.a 也複製好,便可以執行上週的範例了

step02-2_今天要親手打造出 GLUT 的程式,要在一個3D視窗裡,畫出一個黃色的茶壼。前面己把 freeglut裝好, 現在 File-New-Project, GLUT專案,叫作 week03_color, 把 點點點 及 freeglut 都設好, 做出上週的進度, 再刪光光。接下來利用模仿的方式, 寫出 10行程式碼, 便可以做出黃色的茶壼

step03-1_修改前一個程式, 模依 week03-1_color 黃色的茶壼,改成 week03-2_color_triangle 彩色三角形

(用英文輸入法,按下 12345 的左邊有個 反撇 

```C++
///把程式全刪掉!!!!!!
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glColor3f(1,1,0);///黃色
    glutSolidTeapot( 0.3 );/// 0.3 實心茶壼

    glutSwapBuffers();///交換2倍的buffer
}

int main(int argc, char**argv)
{///進階的 main函式
    glutInit( &argc, argv );///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///兩倍 + 3D
    glutCreateWindow("week03的視窗");///建視窗

    glutDisplayFunc( display );///今天用來畫圖的函式

    glutMainLoop();///主要的迴圈
    return 0;
}
```


```C++
///把程式全刪掉!!!!!!
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glColor3f(1,1,0);///黃色
//    glutSolidTeapot( 0.3 );/// 0.3 實心茶壼
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
        glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
        glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);
    glEnd();
    glutSwapBuffers();///交換2倍的buffer
}

int main(int argc, char**argv)
{///進階的 main函式
    glutInit( &argc, argv );///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );///兩倍 + 3D
    glutCreateWindow("week03的彩色三角形視窗");///建視窗

    glutDisplayFunc( display );///今天用來畫圖的函式

    glutMainLoop();///主要的迴圈
    return 0;
}
```
