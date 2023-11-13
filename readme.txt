构建方式：
1) windows下visual studio环境:
	点击visual studio
	选择打开文件夹
	点进主目录下的CMakeLists.txt
	按下保存键(ctrl + s)，即可完成构建
2) 脚本构建:
	运行build脚本(windows下双击build.bat,linux下先用 chmod +x ./build.sh 赋予build.sh可执行权限,再输入 ./build.sh 执行)
	进入构建出的目录(build)
	windows下直接打开build中的sln文件即可
	linux进入build目录,输入 make,即可完成构建(请确保有make,g++(version > 12) 等工具)