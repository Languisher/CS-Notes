# Git 命令速查
（后面还会重写）

## 在分支间
- 创建分支
    - git branch <branch name>
    - 或者 git checkout -b <branch name>
- 切换分支
    - git checkout <branch name>
- 在分支下操作（见“在分支下”）
- 合并分支
    - git checkout <branch name> 切换到分支，通常是 main
    - git merge <branch name> 将 <branch name> 与现在所在的分支合并
- 拉取分支（同步他人的修改所有分支）
    - git pull
    - 某分支 git pull orgin <branch name>
- 删除分支
    - 仅本地：git branch -d <branch name>
    - 远程仓库：git push origin --delete <branch name>

## 在分支下
- 添加文件
    - git add .
    - git add <file>
- 提交修改
    - git commit -m “Commit Information”
- 推送到远程仓库
    - git push
    - 某分支 git push -u origin <branch name>

## 其他
- 克隆远程仓库
    - git clone <remote repository URL>
- 查看 Commit 记录
    - git log
    - 仅某分支：git log <branch name>

## 工作流

```
# 克隆代码库
git clone <repository URL>

# 开始新功能分支
git checkout -b feature/<feature name> develop

# 提交修改
git add .
git commit -m "Commit message"

# 完成功能并合并回 develop 分支
git checkout develop
git merge --no-ff feature/<feature name>
git branch -d feature/<feature name>

# 开始一个新发布分支
git checkout -b release/<release version> develop

# 发布准备工作，如版本号更新、文档编写等
# 当准备完成后，合并回 develop 分支和 master 分支
git checkout master
git merge --no-ff release/<release version>
git tag <release version>
git checkout develop
git merge --no-ff release/<release version>
git branch -d release/<release version>

# 修复问题分支
git checkout -b hotfix/<issue> master
# 提交修改
git add .
git commit -m "Commit message"
# 将修改合并回 master 分支和 develop 分支
git checkout master
git merge --no-ff hotfix/<issue>
git tag <issue>
git checkout develop
git merge --no-ff hotfix/<issue>
git branch -d hotfix/<issue>
```