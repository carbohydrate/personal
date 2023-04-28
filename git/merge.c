// PR merge conflict
// merge main into branch and fix in branch
git checkout main
git pull

git checkout feature123
git pull

git merge main
// will get some output like:
// Auto-merging src/file.ts
// Auto-merging src/file2.ts
// CONFLICT (content): Merge conflict in src/file2.ts
// Automatic merge failed; fix conflicts and then commit the result.

// resolve in editor

git add file2.ts
git commit
git push

// finish PR
