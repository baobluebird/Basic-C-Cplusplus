import os

def create_project_structure():
    base_path = os.getcwd()

    # Cấu trúc thư mục và các file cần tạo
    structure = {
        "build": {},
        "src": {
            "Controller": {
                "ControllerManager.cpp": "#include \"../../include/Controller/ControllerManager.h\"\n",
                "MediaScannerController.cpp": "#include \"../../include/Controller/MediaScannerController.h\"\n",
                "PlayerController.cpp": "#include \"../../include/Controller/PlayerController.h\"\n",
                "MediaPlaylistController.cpp": "#include \"../../include/Controller/MediaPlaylistController.h\"\n",
                "MediaFileController.cpp": "#include \"../../include/Controller/MediaFileController.h\"\n",
                "DeviceController.cpp": "#include \"../../include/Controller/DeviceController.h\"\n",
            },
            "Model": {
                "ModelManager.cpp": "#include \"../../include/Model/ModelManager.h\"\n",
                "CurrentPlay.cpp": "#include \"../../include/Model/CurrentPlay.h\"\n",
                "MediaFile.cpp": "#include \"../../include/Model/MediaFile.h\"\n",
                "AudioFile.cpp": "#include \"../../include/Model/AudioFile.h\"\n",
                "VideoFile.cpp": "#include \"../../include/Model/VideoFile.h\"\n",
                "Playlist.cpp": "#include \"../../include/Model/Playlist.h\"\n",
                "MetadataManager.cpp": "#include \"../../include/Model/MetadataManager.h\"\n",
                "PlaylistManager.cpp": "#include \"../../include/Model/PlaylistManager.h\"\n",
            },
            "View": {
                "CLIManager.cpp": "#include \"../../include/View/CLIManager.h\"\n",
                "ViewBase.cpp": "#include \"../../include/View/ViewBase.h\"\n",
                "ScanView.cpp": "#include \"../../include/View/ScanView.h\"\n",
                "MediaFileView.cpp": "#include \"../../include/View/MediaFileView.h\"\n",
                "MediaFileHandlerView.cpp": "#include \"../../include/View/MediaFileHandlerView.h\"\n",
                "PlaylistView.cpp": "#include \"../../include/View/PlaylistView.h\"\n",
                "PlaylistHandlerView.cpp": "#include \"../../include/View/PlaylistHandlerView.h\"\n",
                "BaseCurrentPlayView.cpp": "#include \"../../include/View/BaseCurrentPlayView.h\"\n",
                "VolumeView.cpp": "#include \"../../include/View/VolumeView.h\"\n",
                "MetadataView.cpp": "#include \"../../include/View/MetadataView.h\"\n",
                "MenuControlPlayView.cpp": "#include \"../../include/View/MenuControlPlayView.h\"\n",
                "BoardManager.cpp": "#include \"../../include/View/BoardManager.h\"\n",
                "S32K144InterfaceLCD.cpp": "#include \"../../include/View/S32K144InterfaceLCD.h\"\n",
            },
            "utils": {
                "Logger.cpp": "#include \"../../include/utils/Logger.h\"\n",
                "ConfigLoader.cpp": "#include \"../../include/utils/ConfigLoader.h\"\n",
            },
        },
        "include": {
            "Controller": {
                "ControllerManager.h": "#ifndef CONTROLLER_MANAGER_H\n#define CONTROLLER_MANAGER_H\n\n#endif\n",
                "MediaScannerController.h": "#ifndef MEDIA_SCANNER_CONTROLLER_H\n#define MEDIA_SCANNER_CONTROLLER_H\n\n#endif\n",
                "PlayerController.h": "#ifndef PLAYER_CONTROLLER_H\n#define PLAYER_CONTROLLER_H\n\n#endif\n",
                "MediaPlaylistController.h": "#ifndef MEDIA_PLAYLIST_CONTROLLER_H\n#define MEDIA_PLAYLIST_CONTROLLER_H\n\n#endif\n",
                "MediaFileController.h": "#ifndef MEDIA_FILE_CONTROLLER_H\n#define MEDIA_FILE_CONTROLLER_H\n\n#endif\n",
                "DeviceController.h": "#ifndef DEVICE_CONTROLLER_H\n#define DEVICE_CONTROLLER_H\n\n#endif\n",
            },
            "Model": {
                "ModelManager.h": "#ifndef MODEL_MANAGER_H\n#define MODEL_MANAGER_H\n\n#endif\n",
                "CurrentPlay.h": "#ifndef CURRENT_PLAY_H\n#define CURRENT_PLAY_H\n\n#endif\n",
                "MediaFile.h": "#ifndef MEDIA_FILE_H\n#define MEDIA_FILE_H\n\n#endif\n",
                "AudioFile.h": "#ifndef AUDIO_FILE_H\n#define AUDIO_FILE_H\n\n#endif\n",
                "VideoFile.h": "#ifndef VIDEO_FILE_H\n#define VIDEO_FILE_H\n\n#endif\n",
                "Playlist.h": "#ifndef PLAYLIST_H\n#define PLAYLIST_H\n\n#endif\n",
                "MetadataManager.h": "#ifndef METADATA_MANAGER_H\n#define METADATA_MANAGER_H\n\n#endif\n",
                "PlaylistManager.h": "#ifndef PLAYLIST_MANAGER_H\n#define PLAYLIST_MANAGER_H\n\n#endif\n",
            },
            "View": {
                "CLIManager.h": "#ifndef CLI_MANAGER_H\n#define CLI_MANAGER_H\n\n#endif\n",
                "ViewBase.h": "#ifndef VIEW_BASE_H\n#define VIEW_BASE_H\n\n#endif\n",
                "ScanView.h": "#ifndef SCAN_VIEW_H\n#define SCAN_VIEW_H\n\n#endif\n",
                "MediaFileView.h": "#ifndef MEDIA_FILE_VIEW_H\n#define MEDIA_FILE_VIEW_H\n\n#endif\n",
                "MediaFileHandlerView.h": "#ifndef MEDIA_FILE_HANDLER_VIEW_H\n#define MEDIA_FILE_HANDLER_VIEW_H\n\n#endif\n",
                "PlaylistView.h": "#ifndef PLAYLIST_VIEW_H\n#define PLAYLIST_VIEW_H\n\n#endif\n",
                "PlaylistHandlerView.h": "#ifndef PLAYLIST_HANDLER_VIEW_H\n#define PLAYLIST_HANDLER_VIEW_H\n\n#endif\n",
                "BaseCurrentPlayView.h": "#ifndef BASE_CURRENT_PLAY_VIEW_H\n#define BASE_CURRENT_PLAY_VIEW_H\n\n#endif\n",
                "VolumeView.h": "#ifndef VOLUME_VIEW_H\n#define VOLUME_VIEW_H\n\n#endif\n",
                "MetadataView.h": "#ifndef METADATA_VIEW_H\n#define METADATA_VIEW_H\n\n#endif\n",
                "MenuControlPlayView.h": "#ifndef MENU_CONTROL_PLAY_VIEW_H\n#define MENU_CONTROL_PLAY_VIEW_H\n\n#endif\n",
                "BoardManager.h": "#ifndef BOARD_MANAGER_H\n#define BOARD_MANAGER_H\n\n#endif\n",
                "S32K144InterfaceLCD.h": "#ifndef S32K144_INTERFACE_LCD_H\n#define S32K144_INTERFACE_LCD_H\n\n#endif\n",
            },
            "utils": {
                "Logger.h": "#ifndef LOGGER_H\n#define LOGGER_H\n\n#endif\n",
                "ConfigLoader.h": "#ifndef CONFIG_LOADER_H\n#define CONFIG_LOADER_H\n\n#endif\n",
            },
        },
        "main.cpp": "#include <iostream>\n\nint main() {\n    std::cout << \"Media Player Entry Point\" << std::endl;\n    return 0;\n}\n",
        "Makefile": "CC=g++\nCFLAGS=-Iinclude\n\nSRC=$(wildcard src/**/*.cpp)\nOBJ=$(SRC:.cpp=.o)\n\nall: main\n\nmain: $(OBJ)\n\t$(CC) -o MediaPlayer main.cpp $(OBJ) $(CFLAGS)\n\nclean:\n\trm -f $(OBJ) MediaPlayer\n",
        ".gitignore": "build/\n*.o\nMediaPlayer\n",
    }

    def create_structure(base, structure):
        for name, content in structure.items():
            path = os.path.join(base, name)
            if isinstance(content, dict):
                os.makedirs(path, exist_ok=True)
                create_structure(path, content)
            else:
                with open(path, "w") as f:
                    f.write(content)

    create_structure(base_path, structure)

if __name__ == "__main__":
    create_project_structure()
    print("Project structure created successfully.")
