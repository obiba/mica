version=1.0-dev
branch=7.x-1.x


#
# Push to Drupal.org
#
git-push:
	sed -i "/^version/d" obiba_protobuf.info && \
	sed -i "/^project/d" obiba_protobuf.info && \
	sed -i "/^datestamp/d" obiba_protobuf.info && \
	$(call git-prepare) . && \
	rsync -av * target/obiba_protobuf --exclude=target --exclude=README.md  --exclude=Makefile && \
	$(call git-finish)

git-prepare = rm -rf target/obiba_protobuf && \
	mkdir -p target/obiba_protobuf && \
	echo "Enter Drupal username?" && \
	read git_username && \
	git clone --recursive --branch $(branch) $$git_username@git.drupal.org:project/obiba_protobuf.git target/obiba_protobuf && \
	cd target/obiba_protobuf && \
	git rm -rf * && \
	cd ../.. && \

git-finish = cd target/obiba_protobuf && \
	git add . && \
	git status && \
	echo "Enter a message for this commit?" && \
	read git_commit_msg && \
	git commit -m "$$git_commit_msg" && \
	git push origin $(branch)
