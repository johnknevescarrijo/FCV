{
  description = "Computer Vision + AI C++ Environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils }:
    utils.lib.eachDefaultSystem (system:
    let
      pkgs = import nixpkgs {
        inherit system;
      };

      opencv4-gtk = pkgs.opencv4.override {
        enableGtk3 = true;
      };

    in {
      devShells.default = pkgs.mkShell {

        packages = with pkgs; [

          # Compiler / Build
          gcc
          llvmPackages.clang
          cmake
          ninja

          # Debug
          gdb
          valgrind

          # LSP
          clang-tools

          # Libraries
          xtensor
          xtl
          xsimd

          opencv4-gtk

          libtorch-bin
        ];

        shellHook = ''
          export CMAKE_PREFIX_PATH="${pkgs.xtensor}:${pkgs.libtorch-bin}:${pkgs.opencv4}:$CMAKE_PREFIX_PATH"

          echo "C++ Environment Ready"
        '';
      };
    });
}