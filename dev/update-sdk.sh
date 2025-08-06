git submodule update --init --recursive && \
cd firmware && \
git pull && \
idf.py sdk && \
cp -r sdk_dist ../sdk_dist && \
echo "Update complete, best commit the sdk_dist files now!"