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
