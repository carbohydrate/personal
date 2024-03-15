git checkout -b temp
git add src/path/to/file/Index.cshtml
git commit
git checkout main
git pull origin main
git checkout temp
git rebase -i main
git checkout main
git merge temp
git push
git push -u origin main

// revert file in branch to origin/main file
git checkout origin/main fileName
git checkout fileName

// delete branch
git branch -d branch_name  // already pushed/merged
git branch -D branch_name  // delete reguardless of push/merge status

// remove untracked and ignored files
git clean -fx

// remove directories
git clean -fd

// stash
git stash list
git stash show -p stash@{1}
git stash save "This is comment"
git stash apply stash@{0}  // taking changes from stash, but saves the stash
git stash pop  // grabs first stash in list and applys changes and removes stash from list
git stash push src/file.ts src/file2.ts  // push 1 or multiple files to one stash

// un-add file before commit
git reset src/file.ts
// or remove all added files from stage
git reset

// remove file from commit
git reset HEAD src/file.ts

// MERGE BRANCH INTO MAIN: https://stackoverflow.com/questions/5601931/what-is-the-best-and-safest-way-to-merge-a-git-branch-into-master
git checkout test
git pull 
git checkout main
git pull
git merge --no-ff --no-commit test
git status
git commit -m 'merge test branch'
git push

// change local user and e-mail
git config --global --edit

// run the following if you commit but have not pushed.  Will let you edit the previous commit before you push.
git reset HEAD~
git commit --amend --reset-author

// push branch that is not created in origin
git push -u origin branchName

// remove local changes
git restore fileName

// untracked stash
git stash --include-untracked

// rename file / move file
git mv fileName newFileName

// accept all incoming changes, incoming wins. During merge
git checkout --theirs fileName.ts

// show url of repo
git remote -v

// have not tried. But maybe set a repo to my fork?
git remote set-url origin https://github.com/myusername/myrepo.git

// create patch from a commit
git show --patch ab555ac425f70b9fcf766775f7d714af1aae164c > 0001-fix-502.patch
// apply patch
git apply -- 0001-fix-502.patch

// stuff for doing multi pull requests in one repo.
// If you haven't set up your remote yet, run this line:
git remote add upstream https://github.com/myusername/myrepo.git
git fetch --all                                   # Get the latest code
git checkout -b my-single-change upstream/main    # Create new branch based on upstream/main
git cherry-pick b50b2e7                           # Cherry pick the commit you want
git push -u origin my-single-change               # Push your changes to the remote branch

git remote add upstream https://github.com/myusername/myrepo.git
git fetch --all  // must do this after adding the remote
git checkout -b fix_502 upstream/main
git push -u origin fix_502

// close github issue (link PR to issue)
// Closes #502
// Closes #423 #421

// working in a cloned repo.  change local to your own fork.  https://gist.github.com/jagregory/710671

// tags
git tag 1.0.1
git push origin 1.0.1
