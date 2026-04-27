{
  description = "C++ with OpenCV (GTK support)";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs = { self, nixpkgs }:
  let
    system = "x86_64-linux";
    pkgs = nixpkgs.legacyPackages.${system};
    # Define a versão personalizada do OpenCV
    opencv4-gtk = pkgs.opencv4.override {
      enableGtk3 = true;
    };
  in {
    devShells.${system}.default = pkgs.mkShell {
      buildInputs = [
        pkgs.gcc
        pkgs.gdb
        pkgs.cmake
        pkgs.ninja
        pkgs.clang-tools
        pkgs.valgrind
        opencv4-gtk   # <--- use a versão com suporte a GTK
        pkgs.xtensor
        pkgs.libtorch-bin
      ];
      shellHook = ''
        export DISPLAY=:0   # se necessário
        echo "Ambiente C++ com OpenCV (GTK) pronto"
      '';
    };
  };
}