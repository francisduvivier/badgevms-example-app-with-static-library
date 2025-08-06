./build.sh
LOCAL_ELF_NAME=sample_app.elf

export BADGEHUB_SAMPLE_APP_API_TOKEN=50af7c9c4c9b9a3c95a6bf2b391c510c
BADGEHUB_PROJECT_SLUG=badgehub_dev
REMOTE_ELF_NAME=hello.elf

curl -X POST -H "badgehub-api-token: ${BADGEHUB_SAMPLE_APP_API_TOKEN}" \
-F "file=@./build/${LOCAL_ELF_NAME}" \
https://badge.why2025.org/api/v3/projects/${BADGEHUB_PROJECT_SLUG}/draft/files/${REMOTE_ELF_NAME} \
&& echo "did upload badgehub.elf to project ${BADGEHUB_PROJECT_SLUG}" && \
curl -X 'PATCH' -H "badgehub-api-token: ${BADGEHUB_SAMPLE_APP_API_TOKEN}" \
  "https://badge.why2025.org/api/v3/projects/${BADGEHUB_PROJECT_SLUG}/publish" \
  -H 'accept: application/json' \
  -H 'Content-Type: application/json' \
&& echo "did publish"