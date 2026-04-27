{
  description = "C++";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs = { self, nixpkgs }:
  let
    system = "x86_64-linux";
    pkgs = nixpkgs.legacyPackages.${system};
  in {
    devShells.${system}.default = pkgs.mkShell {
      buildInputs = [
          pkgs.gcc
          pkgs.gdb
          pkgs.cmake
          pkgs.ninja
          pkgs.clang-tools
          pkgs.valgrind

          #Bibliotecas uteis do c++
          pkgs.opencv4
          pkgs.xtensor
          pkgs.libtorch-bin
      ];
    };
  };
}