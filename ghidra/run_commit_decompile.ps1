# Advisory pseudocode export for hstgen (see scripts/HstCommitDecompile.java). Runs Ghidra headless
# read-only on the private project copy under projects/<slug>; writes out/<slug>-<tag>/.
param(
    [Parameter(Mandatory = $true)][string]$Slug,
    [Parameter(Mandatory = $true)][string]$Tag,
    [int]$Passes = 1,
    [int]$Timeout = 60,
    [string]$Boundaries = ''
)
$ErrorActionPreference = 'Stop'
# Machine-specific paths: hst-config.json in the repository root (or the environment variable HST_<KEY>);
# see hst-config.example.json. Needed: ghidra_headless (analyzeHeadless.bat) and java_home (JDK).
$repo = Split-Path -Parent $PSScriptRoot
function Get-HstSetting([string]$Key) {
    $value = [Environment]::GetEnvironmentVariable('HST_' + $Key.ToUpper())
    if (-not $value) {
        $file = Join-Path $repo 'hst-config.json'
        if (Test-Path -LiteralPath $file) { $value = (Get-Content -LiteralPath $file -Raw -Encoding UTF8 | ConvertFrom-Json).$Key }
    }
    if (-not $value) {
        throw "hst-config: setting '$Key' is not set. Add it to $repo\hst-config.json (copy hst-config.example.json) or set the environment variable HST_$($Key.ToUpper())."
    }
    $value
}
$headless = Get-HstSetting 'ghidra_headless'
$env:JAVA_HOME = Get-HstSetting 'java_home'
$root = $PSScriptRoot
$settings = Join-Path $root 'settings'
$cache = Join-Path $root 'cache'
$env:GHIDRA_HEADLESS_JAVA_OPTIONS = '-Duser.home=' + (Join-Path $settings $env:USERNAME) + ' -Dapplication.settingsdir=' + $settings + ' -Dapplication.cachedir=' + $cache
$project = Join-Path $root ('projects\' + $Slug)
$out = Join-Path $root ('out\' + $Slug + '-' + $Tag)
if (Test-Path -LiteralPath $out) { throw "output exists: $out" }
$null = New-Item -ItemType Directory -Path $out
& $headless $project ('PSPCandidate_' + $Slug) -process -noanalysis -readOnly -max-cpu 4 `
    -scriptPath (Join-Path $root 'scripts') `
    -postScript HstCommitDecompile.java $out $Passes $Timeout $Boundaries 2>&1 | Set-Content -LiteralPath (Join-Path $out 'headless.log') -Encoding UTF8
"EXIT=$LASTEXITCODE"
Get-Content -LiteralPath (Join-Path $out 'headless.log') | Select-String 'HstCommitDecompile|ERROR|Exception' | Select-Object -First 20
