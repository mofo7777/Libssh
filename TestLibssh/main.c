#include "../libssh/libconfig.h"
#include "../libssh/include/libssh.h"

int main()
{
	ssh_init();

	ssh_session ssh = ssh_new();

	if (ssh == NULL)
	{
		return SSH_ERROR;
	}

	int iPort = 22;

	ssh_options_set(ssh, SSH_OPTIONS_HOST, "YourHost");
	ssh_options_set(ssh, SSH_OPTIONS_PORT, &iPort);
	ssh_options_set(ssh, SSH_OPTIONS_USER, "YourPassword");

	int rc = ssh_connect(ssh);

	if (rc != SSH_OK)
	{
		ssh_free(ssh);
		return SSH_ERROR;
	}

	ssh_disconnect(ssh);
	ssh_free(ssh);
	ssh_finalize();

	return SSH_OK;
}