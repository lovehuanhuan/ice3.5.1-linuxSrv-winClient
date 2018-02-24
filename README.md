windos端引入include lib和bin（目标文件）



# ice3.5.1-linuxSrv-winClient
$ g++ -I. -o server demo.cpp server.cpp -lIce -lIceUtil -lpthread
$ g++ -I. -o client demo.cpp client.cpp -lIce -lIceUtil -lpthread
$ ./server

$./client
Hello World!



第一： 下载并安装git

https://git-scm.com/downloads

第二：对git进行全局或单个应用配置

   2.1 全局配置

git config --global user.email "you@example.com"  
git config --global user.name "Your Name"
   2.2  单个应用配置

git config  user.email "you@example.com"  
git config  user.name  "Your Name"

注：只改变红色部分，其他复制



第三：检查是否存在SSH KEYS

    cd   ~/.ssh

第四：如果有 .SSH 目录，请备份好你的 SSH KEY

$ls -a

$mkdir key_backup

$cp id_rsa* key_backup

$rm id_rsa* 

第五：创建新的KEY

ssh-keygen -t rsa -C  "email"



第六：查看生成的KEY

cat  id_rsa.pub 把里面的内容全部复制。



第七：配置GitHub

在账户中找到 settings --> SSH and GPG key -->配置好即可



git的相关操作



第一：在想要上传的文件中使用 git init

第二：使用 git add .  将更改的文件都添加进来

第三：使用 git commit -m '解释语句'，将修改的文件提交到本地仓库

第四：使用git remote add orgin https:yourgithub 

第五：使用 git push -u orgin master 推送到GitHub

-------------更新于 20170913-----------------------

其实github上创建新仓库后就会出现一个流程

echo "# wxvoice" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin https://github.com/whnet/wxvoice.git
git push -u origin master


拉取远程到本地仓库

git pull origin master



如何在git中删除指定的文件和目录

拉取远程的Repo到本地（如果已经在本地，可以略过） 
$ git clone xxxxxx
在本地仓库删除文件 
$ git rm 我的文件
在本地仓库删除文件夹 
$ git rm -r 我的文件夹/
此处-r表示递归所有子目录，如果你要删除的，是空的文件夹，此处可以不用带上-r。
提交代码 
$ git commit -m"我的修改"
推送到远程仓库（比如GitHub） 
$ git push origin xxxxxx
补充: git rm

查看git rm的说明文档:

$ git rm -h
用法：git rm [<选项>] [--] <文件>...

    -n, --dry-run         演习
    -q, --quiet           不列出删除的文件
    --cached              只从索引区删除
    -f, --force           忽略文件更新状态检查
    -r                    允许递归删除
    --ignore-unmatch      即使没有匹配，也以零状态退出
