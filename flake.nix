{
  description = "C++ Environment";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs = { self, nixpkgs }:
  let
    system = "x86_64-linux";
    pkgs = nixpkgs.legacyPackages.${system};
  in {
    devShells.${system}.default = pkgs.mkShell {

      packages = [
        pkgs.gcc
        pkgs.cmake
        pkgs.ninja
        pkgs.clang-tools

        pkgs.xtensor
        pkgs.xtl
        pkgs.xsimd
      ];

      shellHook = ''
        export NIX_CFLAGS_COMPILE="-I${pkgs.xtensor}/include -I${pkgs.xtl}/include -I${pkgs.xsimd}/include $NIX_CFLAGS_COMPILE"

        echo "Ambiente C++ pronto"
      '';
    };
  };
}