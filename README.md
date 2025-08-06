# BadgeVMS example app with a static library included
This repo shows how you can set up cmake for a badgevms app that needs some external library.

## Getting started
- modify `src/sample_app.c` to your liking
- run `build.sh`
- Upload your elf to a project in badgehub, see `# BadgeHub upload`

## updating the badge-vms firmware sdk
For this we have the `./dev/update-sdk.sh`. 
To make this work, first check the firmware submodule's README.md.
Then you can run `./dev/update-sdk.sh` from the root of the repo

## BadgeHub upload
This repo also contains some code that allow you to update an app on badgehub.
To use this, you would first need
- to create a project on https://badge.why2025.org/page/create-project.
- create a project api token
- fill the project api token as well as the project name in the `upload-to-badgehub.sh`
Then you can use
`upload-to-badgehub.sh`
