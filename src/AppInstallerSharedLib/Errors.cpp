// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#include "pch.h"
#include "Public/AppInstallerErrors.h"
#include "Public/AppInstallerLogging.h"
#include "Public/AppInstallerStrings.h"


namespace AppInstaller
{
    namespace
    {
        const char* GetMessageForAppInstallerHR(HRESULT hr)
        {
            switch (hr)
            {
            case APPINSTALLER_CLI_ERROR_INTERNAL_ERROR:
                return "Internal Error";
            case APPINSTALLER_CLI_ERROR_INVALID_CL_ARGUMENTS:
                return "Invalid command line arguments";
            case APPINSTALLER_CLI_ERROR_COMMAND_FAILED:
                return "Executing command failed";
            case APPINSTALLER_CLI_ERROR_MANIFEST_FAILED:
                return "Opening manifest failed";
            case APPINSTALLER_CLI_ERROR_CTRL_SIGNAL_RECEIVED:
                return "Cancellation signal received";
            case APPINSTALLER_CLI_ERROR_SHELLEXEC_INSTALL_FAILED:
                return "Running ShellExecute failed";
            case APPINSTALLER_CLI_ERROR_UNSUPPORTED_MANIFESTVERSION:
                return "Cannot process manifest. The manifest version is higher than supported. Please update the client.";
            case APPINSTALLER_CLI_ERROR_DOWNLOAD_FAILED:
                return "Downloading installer failed";
            case APPINSTALLER_CLI_ERROR_CANNOT_WRITE_TO_UPLEVEL_INDEX:
                return "Cannot write to index; it is a higher schema version";
            case APPINSTALLER_CLI_ERROR_INDEX_INTEGRITY_COMPROMISED:
                return "The index is corrupt";
            case APPINSTALLER_CLI_ERROR_SOURCES_INVALID:
                return "The configured source information is corrupt";
            case APPINSTALLER_CLI_ERROR_SOURCE_NAME_ALREADY_EXISTS:
                return "The source name is already configured";
            case APPINSTALLER_CLI_ERROR_INVALID_SOURCE_TYPE:
                return "The source type is invalid";
            case APPINSTALLER_CLI_ERROR_PACKAGE_IS_BUNDLE:
                return "The MSIX file is a bundle, not a package";
            case APPINSTALLER_CLI_ERROR_SOURCE_DATA_MISSING:
                return "Data required by the source is missing";
            case APPINSTALLER_CLI_ERROR_NO_APPLICABLE_INSTALLER:
                return "None of the installers are applicable for the current system";
            case APPINSTALLER_CLI_ERROR_INSTALLER_HASH_MISMATCH:
                return "The installer file's hash does not match the manifest";
            case APPINSTALLER_CLI_ERROR_SOURCE_NAME_DOES_NOT_EXIST:
                return "The source name does not exist";
            case APPINSTALLER_CLI_ERROR_SOURCE_ARG_ALREADY_EXISTS:
                return "The source location is already configured under another name";
            case APPINSTALLER_CLI_ERROR_NO_APPLICATIONS_FOUND:
                return "No packages found";
            case APPINSTALLER_CLI_ERROR_NO_SOURCES_DEFINED:
                return "No sources are configured";
            case APPINSTALLER_CLI_ERROR_MULTIPLE_APPLICATIONS_FOUND:
                return "Multiple packages found matching the criteria";
            case APPINSTALLER_CLI_ERROR_NO_MANIFEST_FOUND:
                return "No manifest found matching the criteria";
            case APPINSTALLER_CLI_ERROR_EXTENSION_PUBLIC_FAILED:
                return "Failed to get Public folder from source package";
            case APPINSTALLER_CLI_ERROR_COMMAND_REQUIRES_ADMIN:
                return "Command requires administrator privileges to run";
            case APPINSTALLER_CLI_ERROR_SOURCE_NOT_SECURE:
                return "The source location is not secure";
            case APPINSTALLER_CLI_ERROR_MSSTORE_BLOCKED_BY_POLICY:
                return "The Microsoft Store client is blocked by policy";
            case APPINSTALLER_CLI_ERROR_MSSTORE_APP_BLOCKED_BY_POLICY:
                return "The Microsoft Store app is blocked by policy";
            case APPINSTALLER_CLI_ERROR_EXPERIMENTAL_FEATURE_DISABLED:
                return "The feature is currently under development. It can be enabled using winget settings.";
            case APPINSTALLER_CLI_ERROR_MSSTORE_INSTALL_FAILED:
                return "Failed to install the Microsoft Store app";
            case APPINSTALLER_CLI_ERROR_COMPLETE_INPUT_BAD:
                return "Failed to perform auto complete";
            case APPINSTALLER_CLI_ERROR_YAML_INIT_FAILED:
                return "Failed to initialize YAML parser";
            case APPINSTALLER_CLI_ERROR_YAML_INVALID_MAPPING_KEY:
                return "Encountered an invalid YAML key";
            case APPINSTALLER_CLI_ERROR_YAML_DUPLICATE_MAPPING_KEY:
                return "Encountered a duplicate YAML key";
            case APPINSTALLER_CLI_ERROR_YAML_INVALID_OPERATION:
                return "Invalid YAML operation";
            case APPINSTALLER_CLI_ERROR_YAML_DOC_BUILD_FAILED:
                return "Failed to build YAML doc";
            case APPINSTALLER_CLI_ERROR_YAML_INVALID_EMITTER_STATE:
                return "Invalid YAML emitter state";
            case APPINSTALLER_CLI_ERROR_YAML_INVALID_DATA:
                return "Invalid YAML data";
            case APPINSTALLER_CLI_ERROR_LIBYAML_ERROR:
                return "LibYAML error";
            case APPINSTALLER_CLI_ERROR_MANIFEST_VALIDATION_WARNING:
                return "Manifest validation succeeded with warning";
            case APPINSTALLER_CLI_ERROR_MANIFEST_VALIDATION_FAILURE:
                return "Manifest validation failed";
            case APPINSTALLER_CLI_ERROR_INVALID_MANIFEST:
                return "Manifest is invalid";
            case APPINSTALLER_CLI_ERROR_UPDATE_NOT_APPLICABLE:
                return "No applicable update found";
            case APPINSTALLER_CLI_ERROR_UPDATE_ALL_HAS_FAILURE:
                return "winget upgrade --all completed with failures";
            case APPINSTALLER_CLI_ERROR_INSTALLER_SECURITY_CHECK_FAILED:
                return "Installer failed security check";
            case APPINSTALLER_CLI_ERROR_DOWNLOAD_SIZE_MISMATCH:
                return "Download size does not match expected content length";
            case APPINSTALLER_CLI_ERROR_NO_UNINSTALL_INFO_FOUND:
                return "Uninstall command not found";
            case APPINSTALLER_CLI_ERROR_EXEC_UNINSTALL_COMMAND_FAILED:
                return "Running uninstall command failed";
            case APPINSTALLER_CLI_ERROR_ICU_BREAK_ITERATOR_ERROR:
                return "ICU break iterator error";
            case APPINSTALLER_CLI_ERROR_ICU_CASEMAP_ERROR:
                return "ICU casemap error";
            case APPINSTALLER_CLI_ERROR_ICU_REGEX_ERROR:
                return "ICU regex error";
            case APPINSTALLER_CLI_ERROR_IMPORT_INSTALL_FAILED:
                return "Failed to install one or more imported packages";
            case APPINSTALLER_CLI_ERROR_NOT_ALL_PACKAGES_FOUND:
                return "Could not find one or more requested packages";
            case APPINSTALLER_CLI_ERROR_JSON_INVALID_FILE:
                return "Json file is invalid";
            case APPINSTALLER_CLI_ERROR_SOURCE_NOT_REMOTE:
                return "The source location is not remote";
            case APPINSTALLER_CLI_ERROR_UNSUPPORTED_RESTSOURCE:
                return "The configured rest source is not supported";
            case APPINSTALLER_CLI_ERROR_RESTSOURCE_INVALID_DATA:
                return "Invalid data returned by rest source";
            case APPINSTALLER_CLI_ERROR_BLOCKED_BY_POLICY:
                return "Operation is blocked by Group Policy";
            case APPINSTALLER_CLI_ERROR_RESTSOURCE_INTERNAL_ERROR:
                return "Rest source internal error";
            case APPINSTALLER_CLI_ERROR_RESTSOURCE_INVALID_URL:
                return "Invalid rest source url";
            case APPINSTALLER_CLI_ERROR_RESTSOURCE_UNSUPPORTED_MIME_TYPE:
                return "Unsupported MIME type returned by rest source";
            case APPINSTALLER_CLI_ERROR_RESTSOURCE_INVALID_VERSION:
                return "Invalid rest source contract version";
            case APPINSTALLER_CLI_ERROR_SOURCE_DATA_INTEGRITY_FAILURE:
                return "The source data is corrupted or tampered";
            case APPINSTALLER_CLI_ERROR_STREAM_READ_FAILURE:
                return "Error reading from the stream";
            case APPINSTALLER_CLI_ERROR_PACKAGE_AGREEMENTS_NOT_ACCEPTED:
                return "Package agreements were not agreed to";
            case APPINSTALLER_CLI_ERROR_PROMPT_INPUT_ERROR:
                return "Error reading input in prompt";
            case APPINSTALLER_CLI_ERROR_UNSUPPORTED_SOURCE_REQUEST:
                return "The search request is not supported by one or more sources";
            case APPINSTALLER_CLI_ERROR_RESTSOURCE_ENDPOINT_NOT_FOUND:
                return "The rest source endpoint is not found.";
            case APPINSTALLER_CLI_ERROR_SOURCE_OPEN_FAILED:
                return "Failed to open the source.";
            case APPINSTALLER_CLI_ERROR_SOURCE_AGREEMENTS_NOT_ACCEPTED:
                return "Source agreements were not agreed to";
            case APPINSTALLER_CLI_ERROR_CUSTOMHEADER_EXCEEDS_MAXLENGTH:
                return "Header size exceeds the allowable limit of 1024 characters. Please reduce the size and try again.";
            case APPINSTALLER_CLI_ERROR_MISSING_RESOURCE_FILE:
                return "Missing resource file";
            case APPINSTALLER_CLI_ERROR_MSI_INSTALL_FAILED:
                return "Running MSI install failed";
            case APPINSTALLER_CLI_ERROR_INVALID_MSIEXEC_ARGUMENT:
                return "Arguments for msiexec are invalid";
            case APPINSTALLER_CLI_ERROR_FAILED_TO_OPEN_ALL_SOURCES:
                return "Failed to open one or more sources";
            case APPINSTALLER_CLI_ERROR_DEPENDENCIES_VALIDATION_FAILED:
                return "Failed to validate dependencies";
            case APPINSTALLER_CLI_ERROR_MISSING_PACKAGE:
                return "One or more package is missing";
            case APPINSTALLER_CLI_ERROR_INVALID_TABLE_COLUMN:
                return "Invalid table column";
            case APPINSTALLER_CLI_ERROR_UPGRADE_VERSION_NOT_NEWER:
                return "The upgrade version is not newer than the installed version";
            case APPINSTALLER_CLI_ERROR_UPGRADE_VERSION_UNKNOWN:
                return "Upgrade version is unknown and override is not specified";
            case APPINSTALLER_CLI_ERROR_ICU_CONVERSION_ERROR:
                return "ICU conversion error";
            case APPINSTALLER_CLI_ERROR_PORTABLE_INSTALL_FAILED:
                return "Failed to install portable package";
            case APPINSTALLER_CLI_ERROR_PORTABLE_REPARSE_POINT_NOT_SUPPORTED:
                return "Volume does not support reparse points.";
            case APPINSTALLER_CLI_ERROR_PORTABLE_PACKAGE_ALREADY_EXISTS:
                return "Portable package from a different source already exists.";
            case APPINSTALLER_CLI_ERROR_PORTABLE_SYMLINK_PATH_IS_DIRECTORY:
                return "Unable to create symlink, path points to a directory.";
            case APPINSTALLER_CLI_ERROR_INSTALLER_PROHIBITS_ELEVATION:
                return "The installer cannot be run from an administrator context.";
            case APPINSTALLER_CLI_ERROR_PORTABLE_UNINSTALL_FAILED:
                return "Failed to uninstall portable package";
            case APPINSTALLER_CLI_ERROR_ARP_VERSION_VALIDATION_FAILED:
                return "Failed to validate DisplayVersion values against index.";
            case APPINSTALLER_CLI_ERROR_UNSUPPORTED_ARGUMENT:
                return "One or more arguments are not supported.";
            case APPINSTALLER_CLI_ERROR_BIND_WITH_EMBEDDED_NULL:
                return "Embedded null characters are disallowed for SQLite";
            case APPINSTALLER_CLI_ERROR_NESTEDINSTALLER_NOT_FOUND:
                return "Failed to find the nested installer in the archive.";
            case APPINSTALLER_CLI_ERROR_EXTRACT_ARCHIVE_FAILED:
                return "Failed to extract archive.";
            case APPINSTALLER_CLI_ERROR_NESTEDINSTALLER_INVALID_PATH:
                return "Invalid relative file path to nested installer provided.";
            case APPINSTALLER_CLI_ERROR_PINNED_CERTIFICATE_MISMATCH:
                return "The server certificate did not match any of the expected values.";
            case APPINSTALLER_CLI_ERROR_INSTALL_LOCATION_REQUIRED:
                return "Install location must be provided.";
            case APPINSTALLER_CLI_ERROR_ARCHIVE_SCAN_FAILED:
                return "Archive malware scan failed.";
            case APPINSTALLER_CLI_ERROR_PACKAGE_ALREADY_INSTALLED:
                return "Found at least one version of the package installed.";
            case APPINSTALLER_CLI_ERROR_PIN_ALREADY_EXISTS:
                return "A pin already exists for the package.";
            case APPINSTALLER_CLI_ERROR_PIN_DOES_NOT_EXIST:
                return "There is no pin for the package.";
            case APPINSTALLER_CLI_ERROR_CANNOT_OPEN_PINNING_INDEX:
                return "Unable to open the pin database.";
            case APPINSTALLER_CLI_ERROR_MULTIPLE_INSTALL_FAILED:
                return "One or more applications failed to install";
            case APPINSTALLER_CLI_ERROR_MULTIPLE_UNINSTALL_FAILED:
                return "One or more applications failed to uninstall";
            case APPINSTALLER_CLI_ERROR_NOT_ALL_QUERIES_FOUND_SINGLE:
                return "One or more queries did not return exactly one match";
            case APPINSTALLER_CLI_ERROR_PACKAGE_IS_PINNED:
                return "The package has a pin that prevents upgrade.";
            case APPINSTALLER_CLI_ERROR_PACKAGE_IS_STUB:
                return "The package currently installed is the stub package";

            // Install errors
            case APPINSTALLER_CLI_ERROR_INSTALL_PACKAGE_IN_USE:
                return "Application is currently running. Exit the application then try again.";
            case APPINSTALLER_CLI_ERROR_INSTALL_INSTALL_IN_PROGRESS:
                return "Another installation is already in progress. Try again later.";
            case APPINSTALLER_CLI_ERROR_INSTALL_FILE_IN_USE:
                return "One or more file is being used. Exit the application then try again.";
            case APPINSTALLER_CLI_ERROR_INSTALL_MISSING_DEPENDENCY:
                return "This package has a dependency missing from your system.";
            case APPINSTALLER_CLI_ERROR_INSTALL_DISK_FULL:
                return "There's no more space on your PC. Make space, then try again.";
            case APPINSTALLER_CLI_ERROR_INSTALL_INSUFFICIENT_MEMORY:
                return "There's not enough memory available to install. Close other applications then try again.";
            case APPINSTALLER_CLI_ERROR_INSTALL_NO_NETWORK:
                return "This application requires internet connectivity. Connect to a network then try again.";
            case APPINSTALLER_CLI_ERROR_INSTALL_CONTACT_SUPPORT:
                return "This application encountered an error during installation. Contact support.";
            case APPINSTALLER_CLI_ERROR_INSTALL_REBOOT_REQUIRED_TO_FINISH:
                return "Restart your PC to finish installation.";
            case APPINSTALLER_CLI_ERROR_INSTALL_REBOOT_REQUIRED_TO_INSTALL:
                return "Installation failed. Restart your PC then try again.";
            case APPINSTALLER_CLI_ERROR_INSTALL_REBOOT_INITIATED:
                return "Your PC will restart to finish installation.";
            case APPINSTALLER_CLI_ERROR_INSTALL_CANCELLED_BY_USER:
                return "You cancelled the installation.";
            case APPINSTALLER_CLI_ERROR_INSTALL_ALREADY_INSTALLED:
                return "Another version of this application is already installed.";
            case APPINSTALLER_CLI_ERROR_INSTALL_DOWNGRADE:
                return "A higher version of this application is already installed.";
            case APPINSTALLER_CLI_ERROR_INSTALL_BLOCKED_BY_POLICY:
                return "Organization policies are preventing installation. Contact your admin.";
            case APPINSTALLER_CLI_ERROR_INSTALL_DEPENDENCIES:
                return "Failed to install package dependencies.";
            case APPINSTALLER_CLI_ERROR_INSTALL_PACKAGE_IN_USE_BY_APPLICATION:
                return "Application is currently in use by another application.";
            case APPINSTALLER_CLI_ERROR_INSTALL_INVALID_PARAMETER:
                return "Invalid parameter.";
            case APPINSTALLER_CLI_ERROR_INSTALL_SYSTEM_NOT_SUPPORTED:
                return "Package not supported by the system.";
            
            // Status values for check package installed status results.
            case WINGET_INSTALLED_STATUS_ARP_ENTRY_NOT_FOUND:
                return "The Apps and Features Entry for the package could not be found.";
            case WINGET_INSTALLED_STATUS_INSTALL_LOCATION_NOT_APPLICABLE:
                return "The install location is not applicable.";
            case WINGET_INSTALLED_STATUS_INSTALL_LOCATION_NOT_FOUND:
                return "The install location could not be found.";
            case WINGET_INSTALLED_STATUS_FILE_HASH_MISMATCH:
                return "The hash of the existing file did not match.";
            case WINGET_INSTALLED_STATUS_FILE_NOT_FOUND:
                return "File not found.";
            case WINGET_INSTALLED_STATUS_FILE_FOUND_WITHOUT_HASH_CHECK:
                return "The file was found but the hash was not checked.";
            case WINGET_INSTALLED_STATUS_FILE_ACCESS_ERROR:
                return "The file could not be accessed.";

            // Configuration Errors
            case WINGET_CONFIG_ERROR_INVALID_CONFIGURATION_FILE:
                return "The configuration file is invalid.";
            case WINGET_CONFIG_ERROR_INVALID_YAML:
                return "The YAML syntax is invalid.";
            case WINGET_CONFIG_ERROR_INVALID_FIELD_TYPE:
                return "A configuration field has an invalid type.";
            case WINGET_CONFIG_ERROR_UNKNOWN_CONFIGURATION_FILE_VERSION:
                return "The configuration has an unknown version.";
            case WINGET_CONFIG_ERROR_SET_APPLY_FAILED:
                return "An error occurred while applying the configuration.";
            case WINGET_CONFIG_ERROR_DUPLICATE_IDENTIFIER:
                return "The configuration contains a duplicate identifier.";
            case WINGET_CONFIG_ERROR_MISSING_DEPENDENCY:
                return "The configuration is missing a dependency.";
            case WINGET_CONFIG_ERROR_DEPENDENCY_UNSATISFIED:
                return "The configuration has an unsatisfied dependency.";
            case WINGET_CONFIG_ERROR_ASSERTION_FAILED:
                return "An assertion for the configuration unit failed.";
            case WINGET_CONFIG_ERROR_MANUALLY_SKIPPED:
                return "The configuration was manually skipped.";
            case WINGET_CONFIG_ERROR_WARNING_NOT_ACCEPTED:
                return "A warning was thrown and the user declined to continue execution.";
            case WINGET_CONFIG_ERROR_SET_DEPENDENCY_CYCLE:
                return "The dependency graph contains a cycle which cannot be resolved.";
            case WINGET_CONFIG_ERROR_INVALID_FIELD_VALUE:
                return "The configuration has an invalid field value.";
            case WINGET_CONFIG_ERROR_MISSING_FIELD:
                return "The configuration is missing a field.";

            // Configuration Processor Errors
            case WINGET_CONFIG_ERROR_UNIT_NOT_INSTALLED:
                return "The configuration unit was not installed.";
            case WINGET_CONFIG_ERROR_UNIT_NOT_FOUND_REPOSITORY:
                return "The configuration unit could not be found.";
            case WINGET_CONFIG_ERROR_UNIT_MULTIPLE_MATCHES:
                return "Multiple matches were found for the configuration unit; specify the module to select the correct one.";
            case WINGET_CONFIG_ERROR_UNIT_INVOKE_GET:
                return "The configuration unit failed while attempting to get the current system state.";
            case WINGET_CONFIG_ERROR_UNIT_INVOKE_TEST:
                return "The configuration unit failed while attempting to test the current system state.";
            case WINGET_CONFIG_ERROR_UNIT_INVOKE_SET:
                return "The configuration unit failed while attempting to apply the desired state.";
            case WINGET_CONFIG_ERROR_UNIT_MODULE_CONFLICT:
                return "The module for the configuration unit is available in multiple locations with the same version.";
            case WINGET_CONFIG_ERROR_UNIT_IMPORT_MODULE:
                return "Loading the module for the configuration unit failed.";
            case WINGET_CONFIG_ERROR_UNIT_INVOKE_INVALID_RESULT:
                return "The configuration unit returned an unexpected result during execution.";

            default:
                return "Unknown Error Code";
            }
        }

        void GetUserPresentableMessageForHR(std::ostringstream& strstr, HRESULT hr)
        {
            strstr << "0x" << Logging::SetHRFormat << hr << " : ";

            if (HRESULT_FACILITY(hr) == APPINSTALLER_CLI_ERROR_FACILITY)
            {
                strstr << GetMessageForAppInstallerHR(hr);
            }
            else
            {
                strstr << std::system_category().message(hr);
            }
        }
    }

    std::string GetUserPresentableMessage(const wil::ResultException& re)
    {
        const auto& info = re.GetFailureInfo();

        std::ostringstream strstr;

        // We assume that if the exception has a message, that message is relevant to show to the user.
        if (info.pszMessage)
        {
            strstr << Utility::ConvertToUTF8(info.pszMessage) << std::endl;
        }

        GetUserPresentableMessageForHR(strstr, re.GetErrorCode());

        return strstr.str();
    }

    std::string GetUserPresentableMessage(const std::exception& e)
    {
        return e.what();
    }

    std::string GetUserPresentableMessage(HRESULT hr)
    {
        std::ostringstream strstr;
        GetUserPresentableMessageForHR(strstr, hr);
        return strstr.str();
    }

#ifndef WINGET_DISABLE_FOR_FUZZING
    std::string GetUserPresentableMessage(const winrt::hresult_error& hre)
    {
        std::ostringstream strstr;
        GetUserPresentableMessageForHR(strstr, hre.code());
        return strstr.str();
    }
#endif
}
